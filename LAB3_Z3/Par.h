#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Par {
public:
	Par(T *, T *);
	Par(const Par &);
	Par(Par &&);
	~Par();

	Par & operator=(const Par &);
	Par & operator=(Par &&);

	friend bool operator==(const Par<T> &p1, const Par<T> &p2) {
		return *p1.first == *p2.first && *p1.second == *p2.second;
	}
	friend ostream & operator<<(ostream &os, const Par<T> &p) {
		return os << "[" << *p.first << "-" << *p.second << "]";
	}

	T * GetFirst() const;
	T * GetSecond() const;
	void SetFirst(T *);
	void SetSecond(T *);
protected:
private:
	void Copy(const Par &);
	void Move(Par &);
	void Clear();

	T *first, *second;
};

template<typename T>
inline Par<T>::Par(T *t1, T *t2) {
	first = t1;
	second = t2;
}

template<typename T>
inline Par<T>::Par(const Par &p) {
	Copy(p);
}

template<typename T>
inline Par<T>::Par(Par &&p) {
	Move(p);
}

template<typename T>
inline Par<T>::~Par() {
	Clear();
}

template<typename T>
inline Par<T> & Par<T>::operator=(const Par &p) {
	if (this != &p) {
		Clear();
		Copy(p);
	}
	return *this;
}

template<typename T>
inline Par<T> & Par<T>::operator=(Par &&p) {
	if (this != &p) {
		Clear();
		Move();
	}
	return *this;
}

template<typename T>
inline T * Par<T>::GetFirst() const {
	return first;
}

template<typename T>
inline T * Par<T>::GetSecond() const {
	return second;
}

template<typename T>
inline void Par<T>::SetFirst(T *t) {
	delete first;
	first = t;
}

template<typename T>
inline void Par<T>::SetSecond(T *t) {
	delete second;
	second = t;
}

template<typename T>
inline void Par<T>::Copy(const Par &p) {
	first = new T(*p.first);
	second = new T(*p.second);
}

template<typename T>
inline void Par<T>::Move(Par &p) {
	first = p.first;
	second = p.second;
	p.first = p.second = nullptr;
}

template<typename T>
inline void Par<T>::Clear() {
	delete first;
	delete second;
}
