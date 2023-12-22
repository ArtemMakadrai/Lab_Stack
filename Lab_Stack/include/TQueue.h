#include <iostream>
using namespace std;
template <class T>

class TQueue {
protected:
	int MaxSize;
	int first;
	int last;
	int Size;
	T* mas;

public:
	TQueue(int _MaxSize = 0) {
		if (_MaxSize < 0)
			throw "Error lengt";
		else {
			MaxSize = _MaxSize;
			Size = 0;
			mas = new T[MaxSize];
			first = 0;
			last = -1;
		}
	}
	TQueue(const TQueue& tq) {
		MaxSize = tq.MaxSize;
		Size = tq.Size;
		mas = new T[MaxSize];
		first = tq.first;
		last = tq.last;
		for (size_t i = 0; i < Size; i++) {
			mas[(first + i) % MaxSize] = tq.mas[(tq.first + i) % MaxSize];
		}

	}
	~TQueue() {
		delete[] mas;
	}
	bool isEmpty() {
		return (Size == 0);
	}

	bool isFull() {
		return (Size == MaxSize);
	}

	void Push(T a) {
		if (isFull()) throw "Queue is Full";
		if (last == MaxSize - 1) last = 0;
		else {
			last = (last + 1) % MaxSize;
			mas[last] = a;
			Size++;
		}
	}

	T Pop() {
		if (isEmpty())
			throw "Queue is Empty";
		else {
			T a = mas[first];
			first = (first + 1) % MaxSize;
			Size--;
			return a;
		}

	}

	T Top() {
		if (isEmpty())  throw "Queue is empty";
		return mas[first];
	}

	int GetFirst() {
		return first;
	}

	int GetMaxSize() {
		return MaxSize;
	}

	int GetSize() {
		return Size;
	}

	T& operator = (const T& tq) {
		if (MaxSize != tq.MaxSize) {
			delete[] mas;
			MaxSize = tq.MaxSize;
			Size = tq.Size;
			mas = new T[MaxSize];
		}
		for (size_t i = 0; i < MaxSize; i++) {
			mas[i] = tq.mas[i];
		}
		first = tq.first;
		last = tq.last;
		return *this;
	}


};