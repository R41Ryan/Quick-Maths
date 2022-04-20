#include "DoubleLinkedList.h"

template<class T>
Node<T>::Node(T* newItem, Node* newNext, Node* newPrev)
{
	item = newItem;
	next = newNext;
	prev = newPrev;
}

template<class T>
Node<T>::Node()
{
	delete item;
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(T* firstItem)
{
	Node<T>* firstNode = new Node<T>();
	firstNode->item = firstItem;
	headNode = firstNode;
	nodePointer = headNode;
	count = 1;
}

template<class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	headNode = nullptr;
	nodePointer = nullptr;
	count = 0;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{

}

template<class T>
void DoubleLinkedList<T>::addItem(T* newItem)
{
	Node<T> toAdd = new Node<T>();
	toAdd->item = newItem;
	if (nodePointer != nullptr) {
		headNode = toAdd;
	}
	else {
		toAdd->prev = nodePointer;
		toAdd->next = nodePointer->next;
		nodePointer->next = toAdd;
		nodePointer = toAdd->next;
		nodePointer->prev = toAdd;
	}
	nodePointer = toAdd;
	count++;
}

template<class T>
void DoubleLinkedList<T>::removeItem()
{
	if (nodePointer != nullptr) {
		if (nodePointer == headNode) {
			headNode = nodePointer->next;
			delete nodePointer;
			nodePointer = headNode;
		}
		else {
			if (nodePointer->prev != nullptr && nodePointer->next != nullptr) {
				Node<T> prevNode = nodePointer->prev;
				Node<T> nextNode = nodePointer->next;
				prevNode->next = nextNode;
				nextNode->prev = prevNode;
			}
			Node<T>* toDelete = nodePointer;
			nodePointer = nodePointer->next;
			if (nodePointer == nullptr)
				nodePointer = headNode;
			delete toDelete;
		}
		count--;
	}
}
