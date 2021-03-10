#pragma once

#include<exception>
using namespace std;

class ENoCurr : public exception {
public:
	const char * what() const override {
		return "*** Current element does not exist! ***";
	}
};

template <typename T>
class Lista {
public:
	Lista();
	Lista(const Lista &) = delete;
	Lista & operator=(const Lista &) = delete;
	~Lista();

	Lista & AddBeg(const T &);
	Lista & AddEnd(const T &);

	void CurrHead();
	void CurrTail();
	void CurrNext();
	void CurrPrev();
	bool CurrExists();

	T & GetData();
	const T & GetData() const;
	void DeleteData();
protected:
private:
	struct Elem {
		T data;
		Elem *prev, *next;
		Elem(const T &aData, Elem *aPrev = nullptr, Elem *aNext = nullptr);
	};

	Elem *head, *tail;
	mutable Elem *curr;
};

template <typename T>
Lista<T>::Elem::Elem(const T &aData, Elem *aPrev, Elem *aNext) : data(aData), prev(aPrev), next(aNext) {}

template<typename T>
Lista<T>::Lista() {
	head = tail = curr = nullptr;
}

template<typename T>
Lista<T>::~Lista() {
	while (head) {
		curr = head;
		head = head->next;
		delete curr;
	}
	curr = tail = nullptr;
}

template<typename T>
Lista<T> & Lista<T>::AddBeg(const T &t) {
	if (head) {
		head->prev = new Elem(t, nullptr, head);
		head = head->prev;
	}
	else {
		head = tail = new Elem(t);
	}
	return *this;
}

template<typename T>
Lista<T> & Lista<T>::AddEnd(const T &t) {
	if (head) {
		tail->next = new Elem(t, tail);
		tail = tail->next;
	}
	else {
		head = tail = new Elem(t);
	}
	return *this;
}

template<typename T>
inline void Lista<T>::CurrHead() {
	curr = head;
}

template<typename T>
inline void Lista<T>::CurrTail() {
	curr = tail;
}

template<typename T>
inline void Lista<T>::CurrNext() {
	if (curr) {
		curr = curr->next;
	}
}

template<typename T>
inline void Lista<T>::CurrPrev() {
	if (curr) {
		curr = curr->prev;
	}
}

template<typename T>
inline bool Lista<T>::CurrExists() {
	return curr != nullptr;
}

template<typename T>
inline T & Lista<T>::GetData() {
	if (curr) {
		return curr->data;
	}
	else {
		throw ENoCurr();
	}
}

template<typename T>
inline const T & Lista<T>::GetData() const {
	if (curr) {
		return curr->data;
	}
	else {
		throw ENoCurr();
	}
}

template<typename T>
inline void Lista<T>::DeleteData() {
	if (curr) {
		if (curr == head && curr == tail) {
			head = tail = nullptr;
			delete curr;
			curr = nullptr;
		}
		else if (curr == head) {
			head = head->next;
			head->prev = nullptr;
			delete curr;
			curr = nullptr;
		}
		else if (curr == tail) {
			tail = tail->prev;
			tail->next = nullptr;
			delete curr;
			curr = tail;
		}
		else {
			Elem *temp = curr->prev;
			temp->next = curr->next;
			curr->next->prev = temp;
			delete curr;
			curr = temp;
		}

	}
	else {
		throw ENoCurr();
	}
}