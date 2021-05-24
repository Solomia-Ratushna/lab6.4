#pragma once

#include <assert.h>

using namespace std;

template<typename T, typename S = int>
class AQueue
{
public:

	using value_type	  = typename T;
	using reference       = typename T&;
	using const_reference = typename const T&;
	using size_type		  = typename S;

private:

	value_type* values_;
	size_type size_, count_, back_, front_;

	void create(const AQueue<value_type, size_type>& queue)
	{
		for (int i = 0; i != queue.size_; ++i)
		{
			values_[i] = queue.values_[i];
		}
		size_ = queue.size_;
		count_ = queue.count_;
		back_ = queue.back_;
		front_ = queue.front_;
	}

	void copy(AQueue<value_type, size_type>&& queue)
	{
		values_ = queue.values_;
		size_ = queue.size_;
		count_ = queue.count_;
		back_ = queue.back_;
		front_ = queue.front_;
	}

public:

	AQueue(size_type size)
	{
		assert(size > 0);
		size_ = size;
		values_ = new value_type[size];
		back_ = front_ = count_ = 0;
	}

	AQueue(const AQueue<value_type, size_type>& queue)
	{
		create(queue);
	}

	AQueue(AQueue<value_type, size_type>&& queue)
	{
		copy(queue);
	}

	~AQueue()
	{
		delete[] values_;
	}

	size_type size() const
	{
		return size_;
	}

	bool isEmpty() const
	{
		return count_ == 0;
	}

	bool isFull() const
	{
		return count_ == size_;
	}

	void insert(const_reference value)
	{
		assert(!isFull());
		values_[front_++] = value;
		front_ %= size_;
		++count_;
	}

	value_type remove()
	{
		assert(!isEmpty());
		value_type result = values_[back_++];
		back_ %= size_;
		--count_;
		return result;
	}

	const_reference queueTop() const
	{
		assert(!isEmpty());
		return values_[back_];
	}

	friend AQueue<value_type, size_type>& operator>>(AQueue<value_type, size_type>& queue, 
		reference value)
	{
		value = queue.remove();
		return queue;
	}

	friend AQueue<value_type, size_type>& operator<<(AQueue<value_type, size_type>& queue,
		const_reference value)
	{
		queue.insert(value);
		return queue;
	}

	AQueue<value_type, size_type>& operator=(const AQueue<value_type, size_type>& queue)
	{
		if (&queue != this)
		{
			delete[] values_;
			create(queue);
		}
		return *this;
	}

	AQueue<value_type, size_type>& operator=(AQueue<value_type, size_type>&& queue)
	{
		if (&queue != this)
		{
			delete[] values_;
			copy(queue);
		}
		return *this;
	}
};