#pragma once

template <class T>
struct Node {
	T* item;
	Node* next;
	Node* prev;

	Node(T* newItem, Node* newNext, Node* newPrev);
	Node();
	~Node();
};

template <class T>
class DoubleLinkedList {
	Node<T>* headNode;
	Node<T>* nodePointer;
	int count;

public:
	DoubleLinkedList(T* firstItem);
	DoubleLinkedList();
	~DoubleLinkedList();

	/*
	Adds a new node with the newItem to the list to the beginning of the score list (where headNode is). nodePointer points to the new node.
	*/
	void addItem(T* newItem);

	/*
	Removes the node at the top of the list (headNode). If the list is already empty, does nothing. nodePointer moves to the next node after removal.
	*/
	void removeItem();

	/*
	Get the item from the node that nodePointer is pointing at.
	*/
	T* getItem();

	/*
	Get the item from the node referenced by index. (e.g. index = 0 means the item in the headNode)
	*/
	T* getItem(int index);

	/*
	Move the pointer to the node indicated by index.
	*/
	void setPointerIndex(int index);

	/*
	Move the pointer to the next node in the list. If the pointer is already at the end of the list, does nothing.
	*/
	void pointerNext();
	
	/*
	Move the pointer to the previous node in the list. If the pointer is already at the end of the list, does nothing.
	*/
	void pointerPrev();

	/*
	Moves the pointer to the headNode
	*/
	void movePointerToHead();

	/*
	Moves the pointer to the end of the list
	*/
	void movePointerToEnd();

	void setHeadNode(Node<T>* newHead);
	void setNodePointer(Node<T>* newPointer);
	void setCount(int newCount);
	Node<T>* getHead();
	Node<T>* getPointer();
	int getCount();
};