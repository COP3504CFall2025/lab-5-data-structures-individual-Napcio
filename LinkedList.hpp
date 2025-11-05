#pragma once
#include "Interfaces.hpp"
#include <cassert>
#include <iostream>

template <typename T>
class LinkedList : public ContainerInterface<T>
{
	struct Node
	{
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;
		explicit Node(const T& data) : data(data) {}
	};

	// Stores pointers to first and last nodes and count
	Node* head_ = nullptr;
	Node* tail_ = nullptr;
	std::size_t size_ = 0;

	// only if head and tail is nullptr
	void addFirst(const T& data)
	{
		assert(size_ == 0);
		head_ = new Node(data);
		tail_ = head_;
	}

public:
	LinkedList() = default;

	// Behaviors
	void printForward() const
	{
		for (Node* it = head_; it != nullptr; it = it->next)
		{
			std::cout << it->data << "  ";
		}
		std::cout << "\n";
	}
	void printReverse() const
	{
		for (Node* it = tail_; it != nullptr; it = it->prev)
		{
			std::cout << it->data << "  ";
		}
		std::cout << "\n";
	}

	// Accessors
	Node* getHead()
	{
		return head_;
	}
	const Node* getHead() const
	{
		return head_;
	}
	Node* getTail()
	{
		return tail_;
	}
	const Node* getTail() const
	{
		return tail_;
	}

	// Insertion
	void addHead(const T& data)
	{
		if (size_ == 0)
		{
			addFirst(data);
		}
		else
		{
			head_->prev = new Node(data);
			head_->prev->next = head_;
			head_ = head_->prev;
		}
		size_++;
	}
	void addTail(const T& data)
	{
		if (size_ == 0)
		{
			addFirst(data);
		}
		else
		{
			tail_->next = new Node(data);
			tail_->next->prev = tail_;
			tail_ = tail_->next;
		}
		size_++;
	}


	// Removal
	bool removeHead()
	{
		if (size_ < 1)
		{
			return false;
		}
		popHead();
		return true;
	}
	bool removeTail()
	{
		if (size_ < 1)
		{
			return false;
		}
		popTail();
		return true;
	}
	T popHead()
	{
		if (size_ < 1)
		{
			throw std::runtime_error("Container is empty");
		}
		T datum = head_->data;

		Node* oldHead = head_;
		head_ = head_->next;
		if (head_)
		{
			head_->prev = nullptr;
		}
		else
		{
			tail_ = nullptr;
		}
		delete oldHead;

		size_--;
		return datum;
	}
	T popTail()
	{
		if (size_ < 1)
		{
			throw std::runtime_error("Container is empty");
		}
		T datum = tail_->data;

		Node* oldTail = tail_;
		tail_ = tail_->prev;
		if (tail_)
		{
			tail_->next = nullptr;
		}
		else
		{
			head_ = nullptr;
		}
		delete oldTail;

		size_--;
		return datum;
	}
	void clear()
	{
		// it passes through each node, deleting the node behind it until only the tail is left
		for (Node* it = head_; it != nullptr; it = it->next)
		{
			delete it->prev;
		}
		delete tail_;
		head_ = tail_ = nullptr;
		size_ = 0;
	}

	// Big 5
	LinkedList(const LinkedList<T>& other)
	{
		for (Node* it = other.head_; it != nullptr; it = it->next)
		{
			addTail(it->data); // Using built-in function manages size_ for us
		}
	}
	LinkedList(LinkedList<T>&& other) noexcept
	{
		head_ = other.head_;
		tail_ = other.tail_;
		other.head_ = other.tail_ = nullptr;
		size_ = other.size_;
		other.size_ = 0;
	}
	LinkedList<T>& operator=(const LinkedList<T>& other) noexcept
	{
		if (this == &other)
			return *this;

		clear();
		for (Node* it = other.head_; it != nullptr; it = it->next)
		{
			addTail(it->data); // Using built-in function manages size_ for us
		}
		return *this;
	}
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept
	{
		if (this == &other)
			return *this;

		clear();
		head_ = other.head_;
		tail_ = other.tail_;
		other.head_ = other.tail_ = nullptr;
		size_ = other.size_;
		other.size_ = 0;

		return *this;
	}
	~LinkedList() override
	{
		clear();
	}

	// Getters
	[[nodiscard]] std::size_t getSize() const noexcept override
	{
		return size_;
	}
	[[nodiscard]] std::size_t getCount() const noexcept // im not inconsistent the readme is >:(
	{
		return getSize();
	}
};


