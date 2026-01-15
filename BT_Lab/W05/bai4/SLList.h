#pragma once
#include <iostream>
using namespace std;

//Class SLList
template<class T>
class SLList
{
private:
	struct Node
	{
		T info;
		Node* pNext;
	};

	Node* pHead, * pTail;
	int n;

	static Node* CreateNode(const T& value)
	{
		Node* newNode = new Node{ value,nullptr };
		return newNode;
	}

public:
	class Iterator;

	SLList();
	~SLList();

	void AddHead(const T& value);
	void AddTail(const T& value);
	void RemoveHead();
	void RemoveTail();
	void clear();

	int size()
	{
		return n;
	}
	const int size() const
	{
		return n;
	}

	void insert(Iterator pos, const T& value);
	void push_back(const T& value);
	void pop_back();

	T& operator[](int idx);
	const T& operator[](int idx) const;
	SLList<T>& operator=(const SLList<T>& sll);

	Iterator begin()
	{
		return Iterator(pHead);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}

	friend ostream& operator<<(ostream& os, const SLList<T>& ll)
	{
		SLList<T>::Node* tmpNode = ll.pHead;
		while (tmpNode != nullptr)
		{
			os << tmpNode->info << ", ";
			tmpNode = tmpNode->pNext;
		}
		return os;
	}

};

//Defined Class SLList
template<class T>
SLList<T>::SLList()
{
	pHead = pTail = nullptr;
	n = 0;
}

template<class T>
SLList<T>::~SLList()
{
	while (pHead != nullptr)
	{
		Node* tmpNode = pHead;
		pHead = pHead->pNext;
		delete tmpNode;
	}
	pHead = pTail = nullptr;
	n = 0;
}

template<class T>
void SLList<T>::AddHead(const T& value)
{
	Node* newNode = CreateNode(value);
	if (!newNode)
		return;

	if (pHead == nullptr)
		pHead = pTail = newNode;
	else
	{
		newNode->pNext = pHead;
		pHead = newNode;
	}
	n++;
}

template<class T>
void SLList<T>::AddTail(const T& value)
{
	Node* newNode = CreateNode(value);
	if (!newNode)
		return;

	if (pTail == nullptr)
		pHead = pTail = newNode;
	else
	{
		pTail->pNext = newNode;
		pTail = newNode;
	}
	n++;
}

template<class T>
void SLList<T>::RemoveHead()
{
	if (pHead == nullptr)
		return;

	Node* tmpNode = pHead;
	pHead = pHead->pNext;
	delete tmpNode;

	if (pHead == nullptr)
		pHead = pTail = nullptr;

	n--;
}

template<class T>
void SLList<T>::RemoveTail()
{
	if (pTail == nullptr)
		return;

	if (pHead == pTail)
	{
		delete pHead;
		pHead = pTail = nullptr;
		n--;
		return;
	}

	Node* tmpNode = pHead;
	while (tmpNode->pNext != pTail)
	{
		tmpNode = tmpNode->pNext;
	}
	delete pTail;
	pTail = tmpNode;
	n--;
}

template<class T>
void SLList<T>::clear()
{
	while (pHead != nullptr)
	{
		Node* tmpNode = pHead;
		pHead = pHead->pNext;
		delete tmpNode;
	}
	pHead = pTail = nullptr;
	n = 0;
}

template<class T>
void SLList<T>::insert(Iterator pos, const T& value)
{
	if (pos.currentNode == pHead)
	{
		AddHead(value);
		return;
	}

	if (pos.currentNode == nullptr)
	{
		AddTail(value);
		return;
	}

	Node* prev = pHead;
	while (prev && prev->pNext != pos.currentNode)
		prev = prev->pNext;

	if (!prev) //pos is invalid
		return;

	Node* newNode = CreateNode(value);
	if (!newNode) return;
	newNode->pNext = pos.currentNode;
	prev->pNext = newNode;
	n++;
}

template<class T>
void SLList<T>::push_back(const T& value)
{
	AddTail(value);
}

template<class T>
void SLList<T>::pop_back()
{
	RemoveTail();
}

template<class T>
T& SLList<T>::operator[](int idx)
{
	if (idx < 0 || idx >= n)
		throw out_of_range("Index out of range");
	Node* tmp = pHead;
	for (int i = 0; i < idx; i++)
		tmp = tmp->pNext;
	return tmp->info;
}

template<class T>
const T& SLList<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= n)
		throw out_of_range("Index out of range");
	Node* tmp = pHead;
	for (int i = 0; i < idx; i++)
		tmp = tmp->pNext;
	return tmp->info;
}

template<class T>
SLList<T>& SLList<T>::operator=(const SLList<T>& sll)
{
	if (this != &sll)
	{
		clear();
		Node* tmp = sll.pHead;
		while (tmp != nullptr)
		{
			AddTail(tmp->info);
			tmp = tmp->pNext;
		}
	}
	return *this;
}

//Class Iterator and Defined
template<class T>
class SLList<T>::Iterator
{
public:
	using iterator_category = forward_iterator_tag;
	using difference_type = ptrdiff_t;
	using value_type = T;
	using pointer = T*;
	using reference = T&;

private:
	Node* currentNode;
	Iterator(Node* node) : currentNode(node) {}
	friend class SLList<T>;

public:
	Iterator() :currentNode(nullptr) {}

	reference operator*() const
	{
		if (!currentNode)
		{
			throw out_of_range("Dereference end() or null iterator");
		}
		return currentNode->info;
	}

	pointer operator->() const
	{
		if (!currentNode)
			throw out_of_range("Accessing member via end() or null iterator");
		return &(currentNode->info);
	}

	Iterator& operator++()
	{
		if (currentNode)
			currentNode = currentNode->pNext;
		else
			throw out_of_range("Incrementing end() or null iterator");
		return *this;
	}

	Iterator operator++(int)
	{
		if (!currentNode)
			throw out_of_range("Incrementing end() or null iterator");
		Iterator temp = *this;
		currentNode = currentNode->pNext;
		return temp;
	}

	bool operator== (const Iterator& other) const
	{
		return (currentNode == other.currentNode);
	}

	bool operator!=(const Iterator& other) const
	{
		return !(*this == other);
	}
};