#pragma once
#include <algorithm>

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
