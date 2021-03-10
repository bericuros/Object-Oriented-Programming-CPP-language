#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Lista {
public:
	Lista();
	Lista(const Lista &) = delete;
	~Lista();

	Lista & operator=(const Lista &) = delete;
	friend ostream & operator<<(ostream &os, const Lista &l) {
		for (Elem *p = l.head; p; p = p->next) {
			os << p->data << "\n";
		}
		return os;
	}

	Lista & Add(const T &);
protected:
	struct Elem {
		T data;
		Elem *next;
		Elem(const T &aData, Elem *aNext = nullptr);
	};

	Elem *head, *tail;
private:
};

template<typename T>
inline Lista<T>::Elem::Elem(const T & aData, Elem * aNext) : data(aData), next(aNext) {}

template<typename T>
inline Lista<T>::Lista() {
	head = tail = nullptr;
}

template<typename T>
inline Lista<T>::~Lista() {
	while (head) {
		tail = head;
		head = head->next;
		delete tail;
	}
	tail = nullptr;
}

template<typename T>
inline Lista<T> & Lista<T>::Add(const T &t) {
	tail = (!head ? head : tail->next) = new Elem(t);
	return *this;
}