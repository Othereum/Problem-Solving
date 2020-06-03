#include <iostream>

template <class T>
class ForwardList
{
	struct Node
	{
		template <class... Args>
		Node(Args&&... args) :data{std::forward<Args>(args)...}
		{
		}
		
		T data;
		Node* next = nullptr;
	};
	
public:
	using value_type = T;
	
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator& operator++() { cur_ = cur_->next; return *this; }
		Iterator operator++(int) { auto it = *this; ++*this; return it; }
		T* operator->() const { return &cur_->data; }
		T& operator*() const { return cur_->data; }
		bool operator==(const Iterator& r) const { return cur_ == r.cur_; }
		bool operator!=(const Iterator& r) const { return cur_ != r.cur_; }

	private:
		friend ForwardList;
		Iterator(Node* node) :cur_{node} {}
		Node* cur_ = nullptr;
	};

	ForwardList() = default;
	ForwardList(const ForwardList&) = delete;
	ForwardList& operator=(const ForwardList&) = delete;

	ForwardList(ForwardList&& r) noexcept
		:root_{r.root_}
	{
		r.root_ = nullptr;
	}

	ForwardList& operator=(ForwardList&& r) noexcept
	{
		ForwardList{std::move(r)}.swap(*this);
		return *this;
	}

	~ForwardList()
	{
		while (root_)
		{
			auto next = root_->next;
			delete root_;
			root_ = next;
		}
	}

	template <class... Args>
	void emplace_after(Iterator pos, Args&&... args)
	{
		auto node = new Node{std::forward<Args>(args)...};
		auto& cur = pos == before_begin() ? root_ : pos.cur_->next;
		auto next = cur;
		cur = node;
		node->next = next;
	}

	Iterator begin() { return root_; }
	Iterator before_begin() { return reinterpret_cast<Node*>(-1); }
	Iterator end() { return nullptr; }

	void swap(ForwardList& r) noexcept
	{
		std::swap(root_, r.root_);
	}

private:
	Node* root_ = nullptr;
};

template <class T>
class List
{
	struct Node
	{
		template <class... Args>
		Node(Args&&... args) :data{std::forward<Args>(args)...}
		{
		}
		
		T data;
		Node* next = nullptr;
		Node* prev = nullptr;
	};
	
public:
	using value_type = T;
	
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator& operator++() { cur_ = cur_->next; return *this; }
		Iterator operator++(int) { auto it = *this; ++*this; return it; }
		Iterator& operator--() { cur_ = cur_->prev; return *this; }
		Iterator operator--(int) { auto it = *this; --*this; return it; }
		T* operator->() const { return &cur_->data; }
		T& operator*() const { return cur_->data; }
		bool operator==(const Iterator& r) const { return cur_ == r.cur_; }
		bool operator!=(const Iterator& r) const { return cur_ != r.cur_; }

	private:
		friend List;
		Iterator(Node* node) :cur_{node} {}
		Node* cur_ = nullptr;
	};

	class ReverseIterator
	{
	public:
		ReverseIterator() = default;
		ReverseIterator& operator++() { cur_ = cur_->prev; return *this; }
		ReverseIterator operator++(int) { auto it = *this; ++*this; return it; }
		ReverseIterator& operator--() { cur_ = cur_->next; return *this; }
		ReverseIterator operator--(int) { auto it = *this; --*this; return it; }
		T* operator->() const { return &cur_->data; }
		T& operator*() const { return cur_->data; }
		bool operator==(const ReverseIterator& r) const { return cur_ == r.cur_; }
		bool operator!=(const ReverseIterator& r) const { return cur_ != r.cur_; }

	private:
		friend List;
		ReverseIterator(Node* node) :cur_{node} {}
		Node* cur_ = nullptr;
	};

	List() = default;
	List(const List&) = delete;
	List& operator=(const List&) = delete;

	List(List&& r) noexcept
		:root_{r.root_}, tail_{r.tail_}
	{
		r.root_ = nullptr;
		r.tail_ = nullptr;
	}

	List& operator=(List&& r) noexcept
	{
		List{std::move(r)}.swap(*this);
		return *this;
	}
	
	~List()
	{
		while (root_)
		{
			auto next = root_->next;
			delete root_;
			root_ = next;
		}
	}
	
	template <class... Args>
	void emplace_after(Iterator pos, Args&&... args)
	{
		auto node = new Node{std::forward<Args>(args)...};
		auto& cur = pos == before_begin() ? root_ : pos.cur_->next;
		
		auto next = cur;
		cur = node;
		node->next = next;
		
		if (next) next->prev = node;
		if (pos != before_begin()) node->prev = pos.cur_;

		if (!tail_ || tail_ == pos.cur_) tail_ = node;
	}

	Iterator before_begin() { return reinterpret_cast<Node*>(-1); }
	Iterator begin() { return root_; }
	Iterator end() { return nullptr; }
	ReverseIterator rbegin() { return tail_; }
	ReverseIterator rend() { return nullptr; }

	void swap(List& r) noexcept
	{
		std::swap(root_, r.root_);
		std::swap(tail_, r.tail_);
	}

private:
	Node* root_ = nullptr;
	Node* tail_ = nullptr;
};

template <class T, class Fn>
void Gets(Fn fn)
{
	unsigned cnt;
	std::cout << "Count: ";
	std::cin >> cnt;

	T buf;
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cin >> buf;
		fn(buf);
	}
}

template <class List>
void FillList(List& list)
{
	Gets<List::value_type>([&](auto n)
	{
		auto prev = list.before_begin();
		for (auto it = list.begin(); it != list.end() && *it < n; prev = it++) {}
		list.emplace_after(prev, n);
	});
}

int main()
{
	ForwardList<int> flist;
	FillList(flist);
	
	for (auto x : flist) std::cout << x << ' ';
	std::cout << "\n\n";

	
	List<int> list;
	FillList(list);

	std::cout << '\n';
	for (auto x : list) std::cout << x << ' ';
	std::cout << '\n';
	for (auto it = list.rbegin(); it != list.rend(); ++it) std::cout << *it << ' ';
	std::cout << "\n\n";
}
