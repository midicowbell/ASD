#pragma once
#include <cstddef>

#include "../lib_list/list.h" 

template<typename T>
bool fu1(const List<T>& list) {
    if (!list.head() || !list.head()->next) return false;

    typename List<T>::Node<T>* slow = list.head();
    typename List<T>::Node<T>* fast = list.head();

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

template<typename T>
bool fu2(const List<T>& list) {
    if (!list.head() || !list.head()->next) return false;

    typename List<T>::Node<T>* prev = nullptr;
    typename List<T>::Node<T>* curr = list.head();

    while (curr) {
        typename List<T>::Node<T>* next = curr->next;
        curr->next = prev;

        if (next == list.head()) return true;

        prev = curr;
        curr = next;
    }
    return false;
}

template<typename T>
size_t fu3(const List<T>& list) {
    if (!list.head() || !list.head()->next) return static_cast<size_t>(-1);

    typename List<T>::Node<T>* slow = list.head();
    typename List<T>::Node<T>* fast = list.head();

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return static_cast<size_t>(-1);

    slow = list.head();
    size_t index = 0;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
        ++index;
    }
    return index;
}