// Copyright 2025 xd

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "stack.h"

TEST(TestStackLib, can_create_with_init_constructor) {
	ASSERT_NO_THROW(Stack<int> S);
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
TEST(TestStackLib, push_pop_comb) {
	Stack<int> S(20);
	for (int i = 0; i < 20; i++) {
		S.push(i);
	}
	ASSERT_ANY_THROW(S.push(23));
	S.pop();
	S.pop();
	S.pop();
	S.push(245);
	S.push(245);
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
TEST(TestStackLib, top_returns_correct_value) {
	Stack<int> S(10);
	S.push(42);
	EXPECT_EQ(S.top(), 42);

	S.push(100);
	EXPECT_EQ(S.top(), 100);

	S.pop();
	EXPECT_EQ(S.top(), 42);
}

TEST(TestStackLib, top_throws_when_empty) {
	Stack<int> S(10);
	ASSERT_THROW(S.top(), std::logic_error);

	S.push(1);
	S.pop();
	ASSERT_THROW(S.top(), std::logic_error);
}

TEST(TestStackLib, size_method_works_correctly) {
	Stack<int> S(10);
	EXPECT_EQ(S.size(), 0);

	S.push(1);
	EXPECT_EQ(S.size(), 1);

	S.push(2);
	S.push(3);
	EXPECT_EQ(S.size(), 3);

	S.pop();
	EXPECT_EQ(S.size(), 2);

	S.clear();
	EXPECT_EQ(S.size(), 0);
}
TEST(TestStackLib, stress_test_large_operations) {
	const int SIZE = 1000;
	Stack<int> S(SIZE);

	for (int cycle = 0; cycle < 10; cycle++) {
		for (int i = 0; i < SIZE; i++) {
			S.push(i + cycle * 1000);
		}
		EXPECT_TRUE(S.is_full());

		for (int i = 0; i < SIZE; i++) {
			EXPECT_EQ(S.top(), (SIZE - 1 - i) + cycle * 1000);
			S.pop();
		}
		EXPECT_TRUE(S.is_empty());
	}
}