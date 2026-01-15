#include<iostream>
using namespace std;

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
	void Clear();

	Iterator begin()
	{
		return Iterator(pHead);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}

	template<class T>
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
		return nullptr;

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
void SLList<T>::Clear()
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

//Class Iterator
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

#include <algorithm>

void fnAction(int val)
{
	cout << val << ", ";
}

void fnAction2(int& val)
{
	val *= 2;
}

bool fnPredict(int val)
{
	const int threshold = 3;
	return val > threshold;
}

//Main
int main()
{
	SLList<int> l;
	l.AddTail(1);
	l.AddTail(1);
	l.AddTail(0);
	l.AddTail(4);
	l.AddTail(2);
	l.AddTail(5);

	//Duyet su dung iterator (chuan STL)
	for (SLList<int>::Iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;

	//Su dung ham for_each trong algorithm
	for_each(l.begin(), l.end(), fnAction2);
	for_each(l.begin(), l.end(), fnAction);
	cout << endl;

	//Su dung ham replace_if trong algorithm
	replace_if(l.begin(), l.end(), fnPredict, 100);
	cout << l << endl;

	//Su dung ham fill trong algorithm
	fill(l.begin(), l.end(), 123);
	cout << l << endl;

	l.Clear();

	system("pause");
	return 0;
}