#pragma once

#include "Izuzeci.h"

template<typename T>
class Lista {
public:
	Lista();
	Lista(const Lista<T> &) = delete;
	~Lista();

	Lista<T> & operator=(const Lista<T> &) = delete;

	Lista<T> & Add(const T &);
	T & GetData();
	const T & GetData() const;

	void CurrHead() const;
	void CurrNext() const;
	bool CurrExists() const;

	void Clear();
protected:
private:
	struct Elem {
		T data;
		Elem *next;
		Elem(const T &aData, Elem *aNext = nullptr);
	};

	Elem *head, *tail;
	mutable Elem *curr;
};

template<typename T>
inline Lista<T>::Elem::Elem(const T & aData, Elem * aNext) : data(aData), next(aNext) {}

template<typename T>
inline Lista<T>::Lista() {
	head = tail = curr = nullptr;
}

template<typename T>
inline Lista<T>::~Lista() {
	Clear();
}

template<typename T>
inline Lista<T> & Lista<T>::Add(const T &t) {
	tail = (!head ? head : tail->next) = new Elem(t);
	return *this;
}

template<typename T>
inline T & Lista<T>::GetData() {
	if (!curr) {
		throw GNemaTekuci();
	}
	return curr->data;
}

template<typename T>
inline const T & Lista<T>::GetData() const {
	if (!curr) {
		throw GNemaTekuci();
	}
	return curr->data;
}

template<typename T>
inline void Lista<T>::CurrHead() const {
	curr = head;
}

template<typename T>
inline void Lista<T>::CurrNext() const {
	if (curr) {
		curr = curr->next;
	}
}

template<typename T>
inline bool Lista<T>::CurrExists() const {
	return curr != nullptr;
}

template<typename T>
inline void Lista<T>::Clear() {
	while (head) {
		tail = head;
		head = head->next;
		delete tail;
	}
	tail = curr = nullptr;
}
