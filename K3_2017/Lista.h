#pragma once

#include "Izuzeci.h"

template<typename T>
class Lista {
public:
	Lista();
	Lista(const Lista &) = delete;
	~Lista();

	Lista & operator=(const Lista &) = delete;

	int GetSize() const;
	T & GetData() const;
	int & GetInfo() const;

	Lista & Add(const T &, int);
	void CurrHead() const;
	void CurrStep() const;
	bool CurrExists() const;
protected:
private:
	struct Elem {
		T data;
		int info;
		Elem *next;
		Elem(const T &aData, int aInfo, Elem *aNext = nullptr);
	};

	Elem *head, *tail;
	mutable Elem *curr;
	int size;
};

template<typename T>
inline Lista<T>::Elem::Elem(const T &aData, int aInfo, Elem *aNext) : data(aData), info(aInfo), next(aNext) {}

template<typename T>
inline Lista<T>::Lista() {
	head = tail = curr = nullptr;
	size = 0;
}

template<typename T>
inline Lista<T>::~Lista() {
	while (head) {
		curr = head;
		head = head->next;
		delete curr;
	}
	curr = tail = nullptr;
	size = 0;
}

template<typename T>
inline int Lista<T>::GetSize() const {
	return size;
}

template<typename T>
inline T & Lista<T>::GetData() const {
	if (!curr) {
		throw ENoCurr();
	}
	return curr->data;
}

template<typename T>
inline int & Lista<T>::GetInfo() const {
	if (!curr) {
		throw ENoCurr();
	}
	return curr->info;
}

template<typename T>
inline Lista<T> & Lista<T>::Add(const T &d, int i) {
	tail = (!head ? head : tail->next) = new Elem(d, i);
	size++;
	return *this;
}

template<typename T>
inline void Lista<T>::CurrHead() const {
	curr = head;
}

template<typename T>
inline void Lista<T>::CurrStep() const {
	if (curr) {
		curr = curr->next;
	}
}

template<typename T>
inline bool Lista<T>::CurrExists() const {
	return curr != nullptr;
}
