#pragma once

template <class T>
class Stack {
	T* _data;
	size_t _size;
	size_t _top;
public:
	Stack(size_t size) : _size(size), _top(-1) {
		_data = new T[size];
	}

	~Stack() {
		delete[] _data;
	}
};