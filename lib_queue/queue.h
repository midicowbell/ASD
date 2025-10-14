#pragma once

template <class T>
class Queue {
	T* _data;
	int _head;
	int _count;
public:
	void push();
	void pop();
	inline T& head();
	bool is_empty() { return _count == 0; }
	bool is_full() { return _count == _size; }
	void clear() { _head = 0, _count = 0; }



};