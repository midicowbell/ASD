#pragma once
#include "list.h"


template <typename T>
class TStack {
	List<T> _list;
public:
	void push(const T& val);
	void pop();;
	bool is_empty() const;
	T& top();
	void clear();

	
};
template <typename T>
void TStack<T>::push(const T& val) {
	_list.push_front(val);
}
template <typename T>
void TStack<T>::pop() {
	_list.pop_front();
}
template <typename T>
T& TStack<T>::top() {
	return *_list.begin();
}
template <typename T>
bool TStack<T>::is_empty() const {
	return _list.is_empty();
}
template <typename T>
void TStack<T>::clear() {
	_list.clear();
}