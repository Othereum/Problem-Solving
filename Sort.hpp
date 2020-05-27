#pragma once
#include <algorithm>
#include <queue>
#include <numeric>

template <class It, class Compare>
void SelectionSort(It first, It last, Compare comp)
{
	for (auto it = first; it != last; ++it)
	{
		auto min = std::min_element(it, last, comp);
		std::iter_swap(it, min);
	}
}

template <class It>
void SelectionSort(It first, It last) { SelectionSort(first, last, std::less<>{}); }


template <class It, class Compare>
void BubbleSort(It first, It last, Compare comp)
{
	for (auto end = last; end != first; --end)
		for (auto it = first; it != std::prev(end); ++it)
			if (comp(*std::next(it), *it))
				std::iter_swap(it, std::next(it));
}

template <class It>
void BubbleSort(It first, It last) { BubbleSort(first, last, std::less<>{}); }


template <class It, class Compare>
void InsertionSort(It first, It last, Compare comp)
{
	for (auto it = first; it != last; ++it)
	{
		auto target = std::lower_bound(first, it, *it);
		
		for (auto i = it; i != target; --i)
			std::iter_swap(i, std::prev(i));
	}
}

template <class It>
void InsertionSort(It first, It last) { InsertionSort(first, last, std::less<>{}); }


template <class It, class Compare>
void MergeSort(It first, It last, It work, Compare comp)
{
	const auto size = std::distance(first, last);
	if (size <= 1) return;
	
	const auto mid = std::next(first, size / 2);
	MergeSort(first, mid, work, comp);
	MergeSort(mid, last, work, comp);

	auto left = first, right = mid;
	const auto work_end = std::next(work, size);
	for (auto it = work; it != work_end; ++it)
	{
		auto& target = left != mid && (right == last || comp(*left, *right)) ? left : right;
		*it = std::move(*target++);
	}
	std::move(work, work_end, first);
}

template <class It>
void MergeSort(It first, It last, It work) { MergeSort(first, last, work, std::less<>{}); }


template <class It, class Compare>
void GapInsertionSort(It first, It last, ptrdiff_t gap, Compare comp)
{
	for (auto i = first + gap; i < last; i += gap)
	{
		auto key = std::move(*i);
		auto j = i - gap;
		for (; j >= first && comp(key, *j); j -= gap)
		{
			j[gap] = std::move(*j);
		}
		j[gap] = std::move(key);
	}
}

template <class It, class Compare>
void ShellSort(It first, It last, Compare comp)
{
	const auto size = last - first;
	for (auto gap = size / 2; gap > 0; gap /= 2)
	{
		if (gap % 2 == 0) ++gap;
		
		for (auto j = 0; j < gap; j++)
			GapInsertionSort(first+j, last, gap, comp);
	}
}

template <class It>
void ShellSort(It first, It last) { ShellSort(first, last, std::less<>{}); }


template <class It, class Compare>
void QuickSort(const It first, const It last, Compare comp)
{
	if (std::distance(first, last) <= 1) return;

	const auto pivot = std::prev(last);

	auto left = first;
	for (auto it = first; it != last; ++it)
		if (comp(*it, *pivot))
			std::iter_swap(it, left++);
	
	std::iter_swap(left, pivot);

	QuickSort(first, left, comp);
	QuickSort(std::next(left), last, comp);
}

template <class It>
void QuickSort(It first, It last)
{
	QuickSort(first, last, std::less<>{});
}


template <class It, class Compare>
void DownHeap(It it, const It first, const It last, Compare comp)
{
	while (it < last)
	{
		const auto left = it + (it - first) + 1;
		const auto right = left + 1;

		auto next = it;
		if (left < last && comp(*next, *left)) next = left;
		if (right < last && comp(*next, *right)) next = right;
		if (next == it) break;

		std::iter_swap(it, next);
		it = next;
	}
}

template <class It, class Compare>
void Heapify(const It first, const It last, Compare comp)
{
	for (ptrdiff_t i = (last-first-1)/2; i >= 0; --i)
	{
		DownHeap(first + i, first, last, comp);
	}
}

template <class It, class Compare>
void HeapSort(const It first, const It last, Compare comp)
{
	Heapify(first, last, comp);
	for (auto it = last-1; it != first; --it)
	{
		std::iter_swap(first, it);
		DownHeap(first, first, it, comp);
	}
}

template <class It>
void HeapSort(It first, It last)
{
	HeapSort(first, last, std::less<>{});
}


template <class T, class Compare = std::less<>>
class Tree
{
public:
	Tree() = default;
	explicit Tree(Compare comp) :comp_{comp} {}
	
	void Insert(T data)
	{
		if (!root_) root_ = std::make_unique<Node>(std::move(data));
		else root_->Insert(std::move(data), comp_);
	}
	
	template <class Fn>
	void InorderTraversal(Fn&& fn)
	{
		if (root_) root_->InorderTraversal(fn);
	}

private:
	struct Node
	{
		explicit Node(T data) :data{std::move(data)} {}
		
		void Insert(T new_data, Compare comp)
		{
			auto& target = comp(new_data, data) ? left : right;
			if (!target) target = std::make_unique<Node>(std::move(new_data));
			else target->Insert(std::move(new_data), comp);
		}
		
		template <class Fn>
		void InorderTraversal(Fn&& fn)
		{
			if (left) left->InorderTraversal(fn);
			fn(std::move(data));
			if (right) right->InorderTraversal(fn);
		}

		T data;
		std::unique_ptr<Node> left, right;
	};
	
	std::unique_ptr<Node> root_;
	[[no_unique_address]] Compare comp_;
};

template <class It, class Compare>
void TreeSort(It first, const It last, Compare comp)
{
	Tree<typename std::iterator_traits<It>::value_type, Compare> tree{comp};
	
	for (auto it = first; it != last; ++it)
		tree.Insert(std::move(*it));

	tree.InorderTraversal([&first](auto data) { *first++ = std::move(data); });
}

template <class It>
void TreeSort(It first, It last)
{
	TreeSort(first, last, std::less<>{});
}


template <class It>
void RadixSort(const It first, const It last)
{
	using T = typename std::iterator_traits<It>::value_type;
	constexpr auto radix = 10;
	const auto size = static_cast<size_t>(std::distance(first, last));
	
	std::queue<T> buckets[radix];

	for (T div = radix;; div *= radix)
	{
		for (auto it = first; it != last; ++it)
		{
			const auto idx = *it % div / (div/radix);
			buckets[idx].push(std::move(*it));
		}

		auto finish = false;
		auto it = first;

		for (auto& bucket : buckets)
		{
			if (bucket.size() == size) finish = true;
			
			while (!bucket.empty())
			{
				*it++ = std::move(bucket.front());
				bucket.pop();
			}
		}

		if (finish) break;
	}
}


// The output should not be in the [first, last] range.
template <class It>
void CountingSort(const It first, const It last, const It output)
{
	using T = typename std::iterator_traits<It>::value_type;
	std::vector<size_t> count;
	for (auto it = first; it != last; ++it)
	{
		const auto val = static_cast<size_t>(*it);
		if (count.size() <= val) count.resize(val + 1);
		++count[*it];
	}
	std::partial_sum(count.begin(), count.end(), count.begin());
	for (auto it = first; it != last; ++it)
	{
		const auto idx = --count[*it];
		output[idx] = std::move(*it);
	}
}
