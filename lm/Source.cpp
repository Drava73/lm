#include <iostream>
using namespace std;

 template <typename T>
struct Element {
	T Data;
	Element* mPrev, * mNext;
};

template <typename T>
class elem {
	Element<T>* hd, * tail;
	T date;
	int countt;

	void DelAll();
	void AddTail(T data);
	void AddHead(T data);
	void AddSomeWhere(int pos, T data);
	void DelTail();

public:
	elem();
	void Add(T data);
	Element<T> Extract();
	bool Empty();
	void Print();
	~elem();
};

template<typename T>
elem<T>::elem()
{
	hd = tail = NULL;
	countt = 0;
}

template<typename T>
elem<T>::~elem()
{
	DelAll();
}

template<typename T>
void elem<T>::DelAll() {
	Element<T>* ptr;
	while (countt != 0)
	{
		ptr = hd;
		hd = hd->mNext;
		delete ptr;
		countt--;
	}
}

template<typename T>
void elem<T>::AddTail(T data) {
	Element<T>* ptr = new Element<T>;

	tail->mNext = ptr;
	ptr->mPrev = tail;
	ptr->mNext = NULL;
	Tail = ptr;

	Count++;
}

template<typename T>
void elem<T>::AddHead(T data) {
	Element<T>* ptr = new Element<T>;

	if (countt == 0)
	{
		hd = ptr;
		tail = ptr;
		ptr->Data = data;
		ptr->mNext = NULL;
		ptr->mPrev = NULL;
		countt++;
	}
	else
	{
		hd->mPrev = ptr;
		ptr->mNext = hd;
		ptr->Data = data;
		ptr->mPrev = NULL;
		hd = ptr;
		countt++;
	}
}

template<typename T>
void elem<T>::AddSomeWhere(int pos, T data) {

	if (position<0 || position>Count)
	{
		cout << "\n\nError!\n\n";
		exit(1);
	}

	if (position == 0) {
		AddHead(data);
	}

	else if (position == Count - 1) {
		AddTail(data);
	}

	else
	{
		Element<T>* ptr = Head;
		int i = 0;
		while (i < position) {
			ptr = ptr->Next;
			i++;
		}

		Element<T>* prev = ptr;
		Element<T>* next = ptr->Next;
		Element<T>* cur = new Element;
		prev->Next = cur;
		cur->data = data;
		cur->mPrev = prev;
		cur->Next = next;
		next->mPrev = cur;
	}
	Count++;
}

template<typename T>
bool elem<T>::Empty()
{
	if (countt == 0)return true;
	else return false;
}

template<typename T>
void elem<T>::Add(T data)
{
	AddHead(data);
}

template<typename T>
Element<T> elem<T>::Extract()
{
	Element<T>tmp;

	if (!Empty())
	{
		tmp.Data = tail->Data;
		tmp.mNext = tail->mNext;
		tmp.mPrev = tail->mPrev;

		DelTail();
		return tmp;
	}
	else
	{
		return tmp;
	}
}

template<typename T>
void elem<T>::DelTail() {

	if (countt == 1)
	{
		delete tail;
		tail = NULL;
		hd = NULL;
	}
	else
	{
		Element<T>* ptr = tail->mPrev;
		ptr->mNext = NULL;
		delete tail;
		tail = ptr;
	}

	countt--;
}

template<typename T>
void elem<T>::Print()
{
	Element<T>* ptr = hd;

	while (ptr != 0)
	{
		cout << ptr->Data;
		ptr = ptr->mNext;
	}

	cout << "\n\n";
}
int main() {

	elem<char> lQueue;
	lQueue.Add('1');
	lQueue.Add('2');
	lQueue.Add('3');
	 

	lQueue.Print();

	cout << lQueue.Extract().mData;
	cout << lQueue.Extract().mData;
	cout << lQueue.Extract().mData;
	cout << lQueue.Extract().mData;
	cout << lQueue.Extract().mData;

	cout << endl << endl;

	elem<int> lQueue2;
	lQueue2.Add(1);
	lQueue2.Add(2);
	lQueue2.Add(3);
	lQueue2.Add(4);
	lQueue2.Add(5);

	lQueue2.Print();

	cout << lQueue2.Extract().mData;
	cout << lQueue2.Extract().mData;
	cout << lQueue2.Extract().mData;
	cout << lQueue2.Extract().mData;
	cout << lQueue2.Extract().mData;

	cout << endl << endl;

	return 0;
}