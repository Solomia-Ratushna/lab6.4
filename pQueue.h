#pragma once

#include <assert.h>

template<typename T>
class PQueue
{
public:

	using value_type = typename T;
	using reference = typename T&;
	using const_reference = typename const T&;

private:

	class Node
	{
		friend class PQueue;

		value_type info_;
		Node* next_;

		Node() : next_(nullptr) {}
	};

	Node* back_, * front_;

	void create(const PQueue<value_type>& queue)
	{
		back_ = front_ = new Node;
		for (Node* node = queue.back_; node != queue.front_; node = node->next)
		{
			insert(node->info);
		}
	}

	void copy(PQueue<value_type>&& queue)
	{
		back_ = queue.back_;
		front_ = queue.front_;
	}

	void clear()
	{
		while (back_)
		{
			Node* node = back_->next_;
			delete back_;
			back_ = node;
		}
	}

public:

	PQueue()
	{
		back_ = front_ = new Node;
	}

	PQueue(const PQueue<value_type>& queue)
	{
		create(queue);
	}

	PQueue(PQueue<value_type>&& queue) : back_(queue.back_), front_(queue.front_)
	{
		copy(queue);
	}

	~PQueue()
	{
		clear();
	}

	bool isEmpty() const
	{
		return back_ == front_;
	}

	void insert(const_reference value)
	{
		front_->info_ = value;
		front_ = front_->next_ = new Node;
	}

	value_type remove()
	{
		assert(!isEmpty());
		value_type result = back_->info_;
		Node* node = back_->next_;
		delete back_;
		back_ = node;
		return result;
	}

	const_reference queueTop() const
	{
		assert(!isEmpty());
		return back_->info_;
	}

	friend PQueue<value_type>& operator>>(PQueue<value_type>& queue, reference value)
	{
		value = queue.remove();
		return queue;
	}

	friend PQueue<value_type>& operator<<(PQueue<value_type>& queue, const_reference value)
	{
		queue.insert(value);
		return queue;
	}

	PQueue<value_type>& operator=(const PQueue<value_type>& queue)
	{
		if (&queue != this)
		{
			clear();
			create(queue);
		}
		return *this;
	}

	PQueue<value_type>& operator=(PQueue<value_type>&& queue)
	{
		if (&queue != this)
		{
			clear();
			copy(queue);
		}
		return *this;
	}
};