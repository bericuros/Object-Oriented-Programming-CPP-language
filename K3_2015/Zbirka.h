#pragma once

#include "Izuzeci.h"

template<typename T, int cap>
class Zbirka {
public:
	Zbirka();
	~Zbirka();

	Zbirka & operator<<(T *&);
	const Zbirka & operator<<(T *&) const;
	Zbirka & operator>>(T *&);
	const Zbirka & operator>>(T *&) const;

	int GetSize() const;
	void Clear();
protected:
private:
	T *data[cap];
	int front, rear, size;
};

template<typename T, int cap>
inline Zbirka<T, cap>::Zbirka() {
	for (int i = 0; i < cap; i++) {
		data[i] = nullptr;
	}
	front = -1;
	rear = -1;
}

template<typename T, int cap>
inline Zbirka<T, cap>::~Zbirka() {
	Clear();
}

template<typename T, int cap>
inline Zbirka<T, cap> & Zbirka<T, cap>::operator<<(T *&t) {
	if ((rear + 1) % cap == front) {
		throw EFullColl();
	}

	if (front == -1) {
		front = 0;
	}
	rear = (rear + 1) % cap;
	data[rear] = t;

	return *this;
}

template<typename T, int cap>
inline const Zbirka<T, cap> & Zbirka<T, cap>::operator<<(T *&t) const {
	return (const_cast<Zbirka<T, cap> &>(*this)) << t;
}

template<typename T, int cap>
inline Zbirka<T, cap> & Zbirka<T, cap>::operator>>(T *&t) {
	if (front == -1) {
		throw EEmptyColl();
	}

	t = data[front];
	front = (front + 1) % cap;
	if (front == (rear + 1) % cap) {
		front = rear = -1;
	}

	return *this;
}

template<typename T, int cap>
inline const Zbirka<T, cap> & Zbirka<T, cap>::operator>>(T *&t) const {
	return (const_cast<Zbirka<T, cap> &>(*this)) >> t;
}

template<typename T, int cap>
inline int Zbirka<T, cap>::GetSize() const {
	return (rear + cap - front) % cap + (front != -1);
}

template<typename T, int cap>
inline void Zbirka<T, cap>::Clear() {
	int size = (rear - front + cap) % cap + (front != -1);
	while (size--) {
		delete data[front];
		data[front] = nullptr;
		front = (front + 1) % cap;
	}
	front = rear = -1;
}
