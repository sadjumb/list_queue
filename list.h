#pragma once
#include <iostream>

template<class T>
class list;

template<class T>
class Node
{
public:
	Node() : obj(T{}), pNext(), pPrev(){}
	Node(const T& _obj) : obj(_obj), pNext(), pPrev() {}

	T obj;
	std::shared_ptr<Node<T>> pNext;
	std::shared_ptr<Node<T>> pPrev;
	friend class list<T>;
	friend class std::shared_ptr<T>;
};

template<class T>
class list
{
public:
	list() : size(NULL), head(std::make_shared<Node<T>>()), tail(head){};
	list(const list& cp) : size(cp.size), head(std::make_shared<Node<T>>(cp.head.get()->obj)), tail(head)
	{
		//std::cout << tail.get()<< " " << head.get();
		std::shared_ptr<Node<T>> tmp = cp.head;
		while (tmp.get()->pNext.get() != nullptr)
		{
			tail.get()->pNext = std::make_shared<Node<T>>(tmp.get()->pNext.get()->obj);
			tail.get()->pPrev = tail;
			tail = tail.get()->pNext;
			tmp = tmp.get()->pNext;
		}
	}
	void push_back(const T& input)
	{
		if (size == 0)
		{
			tail = head = std::make_shared<Node<T>>(input);
			++size;
			return;
		}
		tail.get()->pNext = std::make_shared<Node<T>>(input);
		tail.get()->pNext.get()->pPrev = tail;
		tail = tail.get()->pNext;
		++size;
	}
	void push_front(const T& input)
	{
		if (size == 0)
		{
			tail = head = std::make_shared<Node<T>>(input);
			++size;
			return;
		}
		head.get()->pPrev = std::make_shared<Node<T>>(input);
		head.get()->pPrev.get()->pNext = head;
		head = head.get()->pPrev;
		++size;
	}

	void pop_back()
	{
		if (size == 0)
			return;
		if (size == 1)
		{
			tail.reset();
			--size;
			return;
		}
		tail = tail.get()->pPrev;
		tail.get()->pNext.reset();
		--size;
	}
	void pop_front()
	{
		if (size == 0)
			return;
		if (size == 1)
		{
			head.reset();
			--size;
			return;
		}
		head = head.get()->pNext;
		head.get()->pPrev.reset();
		--size;
	}

	const T& operator[](size_t index) const
	{
		if (index >= size || index < 0)
			throw std::out_of_range("Error in []");
		std::shared_ptr<Node<T>> tmp = head;
		for (size_t i = 0; i < index; ++i)
		{
			tmp = tmp.get()->pNext;
		}
		return tmp.get()->obj;
	}

	const T& front() const
	{
		return (head.get() == nullptr) ? throw ("Empty list") : head.get()->obj;
	}

	const T& back() const
	{
		return (tail.get() == nullptr) ? throw ("Empty list") : tail.get()->obj;
	}

	T& operator[](size_t index)
	{
		if (index >= size || index < 0)
			throw std::out_of_range("Error in []");
		std::shared_ptr<Node<T>> tmp = head;
		for (size_t i = 0; i < index; ++i)
		{
			tmp = tmp.get()->pNext;
		}
		return tmp.get()->obj;
	}

	size_t get_size() const
	{
		return size;
	}

private:
	size_t size;
	std::shared_ptr<Node<T>> head;
	std::shared_ptr<Node<T>> tail;
};



