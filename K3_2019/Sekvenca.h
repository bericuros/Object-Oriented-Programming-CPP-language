#pragma once

template<typename T>
class Sekvenca {
public:
	Sekvenca();
	Sekvenca(const Sekvenca &);
	Sekvenca(Sekvenca &&);
	~Sekvenca();

	Sekvenca & operator=(const Sekvenca &);
	Sekvenca & operator=(Sekvenca &&);
	T & operator[](int);
	const T &operator[](int) const;

	Sekvenca & Add(const T &);
	T Take();
	int GetSize() const;
protected:
private:
	void Copy(const Sekvenca &);
	void Move(Sekvenca &);
	void Clear();

	struct Elem {
		T data;
		Elem *next;
		Elem(const T &aData, Elem *aNext = nullptr) : data(aData), next(aNext) {}
	};

	Elem *head, *tail;
	int size;
	bool took;
};

template<typename T>
Sekvenca<T>::Sekvenca() {
	head = tail = nullptr;
	size = 0;
	took = false;
}

template<typename T>
Sekvenca<T>::Sekvenca(const Sekvenca &s) {
	Copy(s);
}

template<typename T>
Sekvenca<T>::Sekvenca(Sekvenca &&s) {
	Move(s);
}

template<typename T>
Sekvenca<T>::~Sekvenca() {
	Clear();
}

template<typename T>
Sekvenca<T> & Sekvenca<T>::operator=(const Sekvenca &s) {
	if (this != &s) {
		Clear();
		Copy(s);
	}
	return *this;
}

template<typename T>
Sekvenca<T> & Sekvenca<T>::operator=(Sekvenca &&s) {
	if (this != &s) {
		Clear();
		Move(s);
	}
	return *this;
}

template<typename T>
T & Sekvenca<T>::operator[](int idx) {
	if (idx >= size) {
		throw EInvalidIndex();
	}

	Elem *p = head;
	while (idx--) {
		p = p->next;
	}
	return p->data;
}

template<typename T>
const T & Sekvenca<T>::operator[](int idx) const {
	return const_cast<Sekvenca &> (*this)[idx];
}

template<typename T>
Sekvenca<T> & Sekvenca<T>::Add(const T &t) {
	if (took) {
		throw ENoAdd();
	}
	else {
		Elem *temp = new Elem(t);
		if (!head) {
			head = temp;
		}
		else {
			tail->next = temp;
		}
		tail = temp;
		size++;
	}
}

template<typename T>
T Sekvenca<T>::Take() {
	if (size) {
		T data = head->data;
		Elem *temp = head;

		head = head->next;
		if (!head) tail = nullptr;
		
		delete temp;
		size--;
		took = true;
		
		return data;
	}
	else {
		throw ENoElements();
	}
}

template<typename T>
int Sekvenca<T>::GetSize() const {
	return size;
}

template<typename T>
void Sekvenca<T>::Copy(const Sekvenca &s) {
	head = tail = nullptr;
	for (Elem *p = s.head; p; p = p->next) {
		Elem *temp = new Elem(p->data);
		if (!head) head = temp;
		else tail->next = temp;
		tail = temp;
	}
	size = s.size;
	took = s.took;
}

template<typename T>
void Sekvenca<T>::Move(Sekvenca &s) {
	head = s.head;
	tail = s.tail;
	size = s.size;
	took = s.took;
	s.head = nullptr;
}

template<typename T>
void Sekvenca<T>::Clear() {
	while (head) {
		tail = head;
		head = head->next;
		delete tail;
	}
	head = nullptr;
}








