#pragma once
#include"list.h"

template<class T>
class queue
{
public:
	queue() : size(NULL), qu() {}
	queue(const queue& cp) : size(cp.size), qu(cp.que) {}

	const T& front() const
	{
		return (size == 0) ? throw ("Empty queue") : qu.front();
	}

	void pop_front()
	{
		if (size == 0)
			return;
		--size;
		qu.pop_front();
	}
	void push_back(const T& input)
	{
		++size;
		qu.push_back(input);
	}

	size_t get_size() const
	{
		return size;
	}

	bool isEmpty()
	{
		return (size == 0);
	}

private:
	size_t size;
	list<T> qu;
};