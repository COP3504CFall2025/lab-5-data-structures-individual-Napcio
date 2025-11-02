#pragma once

template <typename T>
class LinkedList : public ContainerInterface<T>
{
	struct Node
	{
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;
		Node(const T& data) : data(data) {}
	};
public:
	// Behaviors
	void printForward() const;
	void printReverse() const;

	// Accessors
	Node* getHead() { return head; }
	const Node* getHead() const { return head; }
	Node* getTail() { return tail; }
	const Node* getTail() const { return tail; }

	// Insertion
	void addHead(const T& data)
	{
		if (head)
		{
			Node* temp = new Node(data);
		}
	}
	void addTail(const T& data);

	// Removal
	bool removeHead();
	bool removeTail();
	void Clear();

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	// Construction/Destruction
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	LinkedList(LinkedList<T>&& other) noexcept;
	~LinkedList();


private:
	// Stores pointers to first and last nodes and count
	Node* head;
	Node* tail;
	std::size_t size;
};


