	#pragma once

template <class T>
class Queue {
	T* _data;
	int _head;
	int _count;
	int _size;
public:
	Queue();
	Queue(int size);
	Queue(const Queue& oth);
	void push(const T& elem);
	void pop();
	inline T& head();
	bool is_empty() { return _count == 0; }
	bool is_full() { return _count == _size; }
	void clear() { _head = 0, _count = 0; }
	
	~Queue() { delete[] _data; }


};
template <class T>
void Queue<T>::push(const T& elem) {
	if (is_full()) {
		throw std::logic_error("out of range");
	}
	_count++;
	_data[(_head+_cout-1)% _size] = elem;
}
template <class T>
void Queue<T>::pop() {
	if (is_empty()) {
		throw std::logic_error("queue is empty");
	}
	_count--;
	_head = (++_head) % _size;
}
template <class T>
Queue<T>::Queue() : _data(nullptr), _size(0), _count(0), _head(0);
template <class T>
Queue<T>::Queue(int size) : _count(0), _head(0), _size(size) {
	_data = new T[_size];
}
template <class T>
Queue<T>::Queue(const Queue& oth): _head(oth._head), _count(oth._count), _size(oth._size) {
	_data = new T[_size];
	for (int i = 0; i < _count; i++) {
		_data[i] = oth._data[i];
	}
}
template <class T>
inline T& Queue<T>::head() {
	return _data[_head];
}