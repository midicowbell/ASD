#include <gtest/gtest.h>
#include "TStack.h"
#include <stdexcept>

TEST(TestTStack, can_create_default_stack) {
    ASSERT_NO_THROW(TStack<int> stack);
}

TEST(TestTStack, new_stack_is_empty) {
    TStack<int> stack;
    EXPECT_TRUE(stack.is_empty());
}

TEST(TestTStack, push_makes_stack_not_empty) {
    TStack<int> stack;
    stack.push(1);
    EXPECT_FALSE(stack.is_empty());
}

TEST(TestTStack, can_push_elements) {
    TStack<int> stack;
    ASSERT_NO_THROW(stack.push(10));
    ASSERT_NO_THROW(stack.push(20));
    ASSERT_NO_THROW(stack.push(30));
}

TEST(TestTStack, top_returns_last_pushed_element) {
    TStack<int> stack;
    stack.push(10);
    EXPECT_EQ(stack.top(), 10);

    stack.push(20);
    EXPECT_EQ(stack.top(), 20);

    stack.push(30);
    EXPECT_EQ(stack.top(), 30);
}

TEST(TestTStack, can_pop_elements) {
    TStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    ASSERT_NO_THROW(stack.pop());
    ASSERT_NO_THROW(stack.pop());
    ASSERT_NO_THROW(stack.pop());
}

TEST(TestTStack, pop_removes_top_element) {
    TStack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    EXPECT_EQ(stack.top(), 30);
    stack.pop();
    EXPECT_EQ(stack.top(), 20);
    stack.pop();
    EXPECT_EQ(stack.top(), 10);
}

TEST(TestTStack, lifo_behavior) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.top(), 3);
    stack.pop();

    EXPECT_EQ(stack.top(), 2);
    stack.pop();

    EXPECT_EQ(stack.top(), 1);
    stack.pop();

    EXPECT_TRUE(stack.is_empty());
}

TEST(TestTStack, pop_throws_when_empty) {
    TStack<int> stack;
    EXPECT_THROW(stack.pop(), std::runtime_error);

    stack.push(1);
    stack.pop();
    EXPECT_THROW(stack.pop(), std::runtime_error);
}

TEST(TestTStack, can_clear_stack) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_FALSE(stack.is_empty());
    stack.clear();
    EXPECT_TRUE(stack.is_empty());
}

TEST(TestTStack, can_reuse_after_clear) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.clear();

    stack.push(100);
    EXPECT_EQ(stack.top(), 100);
    EXPECT_FALSE(stack.is_empty());
}

TEST(TestTStack, multiple_push_pop_operations) {
    TStack<int> stack;

    for (int i = 0; i < 5; i++) {
        stack.push(i);
        EXPECT_EQ(stack.top(), i);
    }

    for (int i = 4; i >= 0; i--) {
        EXPECT_EQ(stack.top(), i);
        stack.pop();
    }

    EXPECT_TRUE(stack.is_empty());
}

TEST(TestTStack, stress_test) {
    TStack<int> stack;

    for (int i = 0; i < 1000; i++) {
        stack.push(i);
        EXPECT_EQ(stack.top(), i);
    }

    for (int i = 999; i >= 0; i--) {
        EXPECT_EQ(stack.top(), i);
        stack.pop();
    }

    EXPECT_TRUE(stack.is_empty());
}

TEST(TestTStack, works_with_different_types) {
    TStack<std::string> stack;
    stack.push("hello");
    stack.push("world");

    EXPECT_EQ(stack.top(), "world");
    stack.pop();
    EXPECT_EQ(stack.top(), "hello");
}

TEST(TestTStack, top_allows_modification) {
    TStack<int> stack;
    stack.push(1);

    stack.top() = 100;
    EXPECT_EQ(stack.top(), 100);
}
