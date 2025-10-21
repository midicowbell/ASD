#pragma once

template <class T>
class Stack {
	T* _data;
	int _size;
	int _top;
public:
	Stack() : _size(0), _top(-1), _data(nullptr) {};
	Stack(int size) : _size(size), _top(-1) {
		_data = new T[size];
	}

	Stack(const Stack& oth) : _size(oth._size), _top(oth._top) {
		_data = new T[_size];
		for (int i = 0; i <= _top; i++) {
			_data[i] = oth._data[i];
		}
	}

	~Stack() {
		delete[] _data;
	}
	void push(const T& item);
	void pop();
	bool is_full() noexcept  { return _top == _size - 1; }
	bool is_empty() noexcept  { return _top == -1; }
	T& top()  {
		if (is_empty()) {
			throw std::logic_error("stack is empty");
		 }
		return _data[_top]; 
	}
	void clear() noexcept { _top = -1; }
	int size() { return _top + 1; }
};

template <class T>
void Stack<T> ::push(const T& item) {
	if (is_full()) {
		throw std::logic_error("out of range");
	}
	_data[++_top] = item;
}
template <class T>
void Stack<T> ::pop() {
	if (is_empty()) {
		throw std::logic_error("stack is empty");
	}
	_top--;
}