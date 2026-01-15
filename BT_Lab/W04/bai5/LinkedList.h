#pragma once
#include <iostream>
#include <exception>
using namespace std;

template<class T>
struct Node
{
	T info;
	Node* pNext;
};

template<class T>
class LinkedList
{
private:
	Node<T>* pHead, * pTail;
	int n;

	static Node<T>* CreateNode(const T& value);

public:
	LinkedList();
	
	~LinkedList();

	Node<T>* AddHead(const T& value);
	Node<T>* AddTail(const T& value);
	Node<T>* RemoveHead();
	Node<T>* RemoveTail();

	T& operator[](const int& i);
	const T& operator[](const int& i) const;

	int getSize();
	void clear();

	template<class U>
	friend ostream& operator<<(ostream& os, const LinkedList<U>& ll);
};

template<class T>
int LinkedList<T>::getSize()
{
	return n;
}

template<class T>
void LinkedList<T>::clear()
{
	while (pHead)
		RemoveHead();
}

//Define LinkedList
template<class T>
LinkedList<T>::LinkedList()
{
	pHead = pTail = nullptr;
	n = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* node = pHead;
	while (pHead != nullptr)
	{
		pHead = pHead->pNext;
		delete node;
		node = pHead;
	}
	pHead = pTail = nullptr;
	n = 0;
}

template<class T>
Node<T>* LinkedList<T>::CreateNode(const T& value)
{
	Node<T>* newNode = new Node<T>{ value,nullptr };
	return newNode;
}

template<class T>
Node<T>* LinkedList<T>::AddHead(const T& value)
{
	Node<T>* newNode = CreateNode(value);
	if (newNode == nullptr)
		return nullptr;
	if (pHead == nullptr)
	{
		pHead = pTail = newNode;
	}
	else
	{
		newNode->pNext = pHead;
		pHead = newNode;
	}
	n++;
	return newNode;
}

template<class T>
Node<T>* LinkedList<T>::AddTail(const T& value)
{
	Node<T>* newNode = CreateNode(value);
	if (newNode == nullptr)
	{
		return nullptr;
	}
	if (pHead == nullptr)
	{
		pHead = pTail = newNode;
		n++;
		return newNode;
	}
	pTail->pNext = newNode;
	pTail = newNode;
	n++;
	return newNode;
}

template<class T>
Node<T>* LinkedList<T>::RemoveHead()
{
	if (pHead == nullptr)
		return nullptr;
	Node<T>* tmpNode = pHead;
	pHead = pHead->pNext;
	n--;
	if (pHead == nullptr)
		pTail = nullptr;
	return tmpNode;
}

template<class T>
Node<T>* LinkedList<T>::RemoveTail()
{
	if (pTail == nullptr)
		return nullptr;

	Node<T>* removed = pTail;

	if (pHead == pTail)
	{
		pHead = pTail = nullptr;
		n--;
		return removed;
	}
	Node<T>* tmpNode = pHead;
	while (tmpNode->pNext != pTail)
		tmpNode = tmpNode->pNext;
	tmpNode->pNext = nullptr;
	pTail = tmpNode;
	n--;
	return removed;
}

template<class T>
T& LinkedList<T>::operator[](const int& i)
{
	if (i < 0 || i >= n)
		throw exception("Out of range");
	Node<T>* tmpNode = pHead;
	int cnt = 0;
	while (cnt != i)
	{
		tmpNode = tmpNode->pNext;
		cnt++;
	}
	return tmpNode->info;
}

template<class T>
const T& LinkedList<T>::operator[](const int& i) const
{
	if (i < 0 || i >= n)
		throw exception("Out of range");
	Node<T>* tmpNode = pHead;
	int cnt = 0;
	while (cnt != i)
	{
		tmpNode = tmpNode->pNext;
		cnt++;
	}
	return tmpNode->info;
}

template<class T>
ostream& operator<<(ostream& os, const LinkedList<T>& ll)
{
	Node<T>* tmpNode = ll.pHead;
	while (tmpNode != nullptr)
	{
		os << tmpNode->info << ", ";
		tmpNode = tmpNode->pNext;
	}
	return os;
}

