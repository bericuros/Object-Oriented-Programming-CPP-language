#pragma once

#include <iostream>
using namespace std;

#include "Izuzeci.h"

template<typename T>
class Lista {
public:
	Lista();
	Lista(const Lista<T> &);
	Lista(Lista<T> &&);
	virtual ~Lista();

	Lista<T> & operator=(const Lista<T> &);
	Lista<T> & operator=(Lista<T> &&);
	Lista<T> & operator+=(const T &);
	T * operator-();
	T * operator*();
	friend ostream & operator<<(ostream &os, const Lista<T> &l) {
		for (Elem *p = l.head; p; p = p->next) {
			os << *p->data << " ";
		}
		return os;
	}

	int GetSize() const;
protected:
private:
	void Copy(const Lista<T> &);
	void Move(Lista<T> &);
	void Clear();

	struct Elem {
		T *data;
		Elem *prev, *next;
		Elem(T *aData, Elem *prev = nullptr, Elem *aNext = nullptr);
	};
	Elem *head, *tail;
	int size;
};

template<typename T>
inline Lista<T>::Elem::Elem(T *aData, Elem *aPrev, Elem *aNext) : data(aData), prev(aPrev), next(aNext) {}

template<typename T>
inline Lista<T>::Lista() {
	head = tail = nullptr;
	size = 0;
}

template<typename T>
inline Lista<T>::Lista(const Lista<T> &l) {
	Copy(l);
}

template<typename T>
inline Lista<T>::Lista(Lista<T> &&l) {
	Move(l);
}

template<typename T>
inline Lista<T>::~Lista() {
	Clear();
}

template<typename T>
inline Lista<T> & Lista<T>::operator=(const Lista<T> &l) {
	if (this != &l) {
		Clear();
		Copy(l);
	}
	return *this;
}

template<typename T>
inline Lista<T> & Lista<T>::operator=(Lista<T> &&l) {
	if (this != &l) {
		Clear();
		Move(l);
	}
	return *this;
}

template<typename T>
inline Lista<T> & Lista<T>::operator+=(const T &t) {
	tail = (!head ? head : tail->next) = new Elem(t.Copy(), tail);
	size++;
	return *this;
}

template<typename T>
inline T * Lista<T>::operator-() {
	if (!head) {
		throw GPrazna();
	}

	T *t = tail->data;
	Elem *temp = tail;
	tail = tail->prev;
	if (tail) {
		tail->next = nullptr;
	}
	else {
		head = nullptr;
	}

	delete temp;
	size--;

	return t;
}

template<typename T>
inline T * Lista<T>::operator*() {
	if (!head) {
		throw GPrazna();
	}
	
	T *t = head->data;
	Elem *temp = head;
	head = head->next;
	if (head) {
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}

	delete temp;
	size--;

	return t;
}

template<typename T>
inline int Lista<T>::GetSize() const {
	return size;
}

template<typename T>
inline void Lista<T>::Copy(const Lista<T> &l) {
	size = l.size;
	for (Elem *p = l.head; p; p = p->next) {
		tail = (!head ? head : tail->next) = new Elem(p->data->Copy(), tail);
	}
}

template<typename T>
inline void Lista<T>::Move(Lista<T> &l) {
	size = l.size;
	head = l.head;
	tail = l.tail;
	l.head = nullptr;
}

template<typename T>
inline void Lista<T>::Clear() {
	while (head) {
		tail = head;
		head = head->next;
		delete tail->data;
		delete tail;
	}
	tail = nullptr;
	size = 0;
}
