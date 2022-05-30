#include "DoubleLinkedList.h"
#include "Score.h"

template struct Node<Score>;
template class DoubleLinkedList <Score>;

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
}

template<class T>
Node<T>::~Node()
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
	nodePointer = headNode;
	count = 0;
}

template<class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{

}

template<class T>
void DoubleLinkedList<T>::addItem(T* newItem)
{
	Node<T>* toAdd = new Node<T>();
	toAdd->item = newItem;
	if (headNode == nullptr) 
	{
		headNode = toAdd;
	}
	else 
	{
		toAdd->next = headNode;
		headNode = toAdd;
		toAdd->next->prev = toAdd;

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
				Node<T>* prevNode = nodePointer->prev;
				Node<T>* nextNode = nodePointer->next;
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

template<class T>
T* DoubleLinkedList<T>::getItem()
{
	return nodePointer->item;
}

template<class T>
T* DoubleLinkedList<T>::getItem(int index)
{
	return nullptr;
}

template<class T>
void DoubleLinkedList<T>::setPointerIndex(int index)
{
	movePointerToHead();
	for (int i = 0; i < index; i++)
	{
		pointerNext();
	}
}

template<class T>
void DoubleLinkedList<T>::pointerNext()
{
	if (nodePointer->next != nullptr)
	{
		nodePointer = nodePointer->next;
	}
}

template<class T>
void DoubleLinkedList<T>::pointerPrev()
{
	if (nodePointer->prev != nullptr)
	{
		nodePointer = nodePointer->prev;
	}
}

template<class T>
void DoubleLinkedList<T>::movePointerToHead()
{
	nodePointer = headNode;
}

template<class T>
void DoubleLinkedList<T>::movePointerToEnd()
{
	movePointerToHead();
	for (int i = 0; i < count - 1; i++)
	{
		pointerNext();
	}
}

template<class T>
void DoubleLinkedList<T>::setHeadNode(Node<T>* newHead)
{
	headNode = newHead;
}

template<class T>
void DoubleLinkedList<T>::setNodePointer(Node<T>* newPointer)
{
	nodePointer = newPointer;
}

template<class T>
void DoubleLinkedList<T>::setCount(int newCount)
{
	count = newCount;
}

template<class T>
Node<T>* DoubleLinkedList<T>::getHead()
{
	return headNode;
}

template<class T>
Node<T>* DoubleLinkedList<T>::getPointer()
{
	return nodePointer;
}

template<class T>
int DoubleLinkedList<T>::getCount()
{
	return count;
}
