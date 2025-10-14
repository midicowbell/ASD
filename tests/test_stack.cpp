// Copyright 2025 xd

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "stack.h"

TEST(TestStackLib, can_create_with_init_constructor) {
	ASSERT_NO_THROW(Stack<int> S(20));

}
TEST(TestStackLib, can_create_with_copy_constructor) {
	Stack<int> S(20);
	ASSERT_NO_THROW(Stack<int> D(S));

}
TEST(TestStackLib, is_full) {
	Stack<int> S(20);
	for (int i = 0; i < 20; i++) {
		S.push(i);
	}
	ASSERT_TRUE(S.is_full());
}
TEST(TestStackLib, is_empty) {
	Stack<int> S(20);
	ASSERT_TRUE(S.is_empty());
}
TEST(TestStackLib, push_with_full) {
	Stack<int> S(20);
	for (int i = 0; i < 20; i++) {
		S.push(i);
	}
	ASSERT_ANY_THROW(S.push(23));
	S.pop();
	S.push(245);
	ASSERT_ANY_THROW(S.push(23123));

}
TEST(TestStackLib, pop_with_empty) {
	Stack<int> S(20);
	ASSERT_ANY_THROW(S.pop());

}
TEST(TestStackLib, clear) {
	Stack<int> S(20);
	for (int i = 0; i < 20; i++) {
		S.push(i);
	}
	S.clear();
	ASSERT_TRUE(S.is_empty());

}

