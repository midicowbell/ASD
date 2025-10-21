// Copyright 2025 xd

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "queue.h"
TEST(TestQueueLib, can_create_default_queue) {
    Queue<int> Q;
    EXPECT_TRUE(Q.is_empty());
    EXPECT_EQ(Q.size(), 0);
}

TEST(TestQueueLib, can_create_queue_with_size) {
    Queue<int> Q(10);
    EXPECT_TRUE(Q.is_empty());
    EXPECT_FALSE(Q.is_full());
    EXPECT_EQ(Q.size(), 10);
}

TEST(TestQueueLib, can_push_elements) {
    Queue<int> Q(5);

    Q.push(1);
    EXPECT_FALSE(Q.is_empty());
    EXPECT_EQ(Q.count(), 1);

    Q.push(2);
    Q.push(3);
    EXPECT_EQ(Q.count(), 3);
}

TEST(TestQueueLib, can_pop_elements) {
    Queue<int> Q(5);
    Q.push(10);
    Q.push(20);
    Q.push(30);

    EXPECT_EQ(Q.head(), 10);
    Q.pop();
    EXPECT_EQ(Q.head(), 20);
    EXPECT_EQ(Q.count(), 2);

    Q.pop();
    EXPECT_EQ(Q.head(), 30);
    EXPECT_EQ(Q.count(), 1);
}

TEST(TestQueueLib, can_handle_circular_behavior) {
    Queue<int> Q(3);
    Q.push(1);
    Q.push(2);
    Q.push(3);

    Q.pop();
    Q.push(4); 

    EXPECT_EQ(Q.head(), 2);
    Q.pop();
    EXPECT_EQ(Q.head(), 3);
    Q.pop();
    EXPECT_EQ(Q.head(), 4);
}

TEST(TestQueueLib, push_throws_when_full) {
    Queue<int> Q(2);
    Q.push(1);
    Q.push(2);

    EXPECT_THROW(Q.push(3), std::logic_error);
}

TEST(TestQueueLib, pop_throws_when_empty) {
    Queue<int> Q(5);
    EXPECT_THROW(Q.pop(), std::logic_error);

    Q.push(1);
    Q.pop();
    EXPECT_THROW(Q.pop(), std::logic_error);
}

TEST(TestQueueLib, can_clear_queue) {
    Queue<int> Q(5);
    Q.push(1);
    Q.push(2);
    Q.push(3);

    EXPECT_FALSE(Q.is_empty());
    Q.clear();
    EXPECT_TRUE(Q.is_empty());
    EXPECT_EQ(Q.count(), 0);
}
TEST(TestQueueLib, is_full_works_correctly) {
    Queue<int> Q(3);
    EXPECT_FALSE(Q.is_full());

    Q.push(1);
    EXPECT_FALSE(Q.is_full());

    Q.push(2);
    EXPECT_FALSE(Q.is_full());

    Q.push(3);
    EXPECT_TRUE(Q.is_full());

    Q.pop();
    EXPECT_FALSE(Q.is_full());
}
TEST(TestQueueLib, stress_test) {
    Queue<int> Q(1000);

    // Заполняем очередь
    for (int i = 0; i < 1000; i++) {
        Q.push(i);
    }
    EXPECT_TRUE(Q.is_full());

    // Опустошаем очередь
    for (int i = 0; i < 1000; i++) {
        EXPECT_EQ(Q.head(), i);
        Q.pop();
    }
    EXPECT_TRUE(Q.is_empty());
}