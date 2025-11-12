#pragma once
#include "list.h"
template <typename T>
class TQueue {
	List<T> _list;
public:
	void push(const T& val);
	void pop();
	inline T& head();
	inline  bool is_empty();
	void clear();
};
template <typename T>
void TQueue<T>::push(const T& val) {
	_list.push_back(val);
}
template <typename T>
void TQueue<T>::pop() {
	_list.pop_front();
}
template <typename T>
T& TQueue<T>::head() {
	return _list.front();
}
template <typename T>
bool TQueue<T>::is_empty() {
	return _list.is_empty();
}
template <typename T>
void TQueue<T>::clear() {
	_list.clear();
}

