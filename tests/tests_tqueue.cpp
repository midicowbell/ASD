#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "tqueue.h"


TEST(TestTQueue, can_create_default_queue) {
    TQueue<int> Q;
    EXPECT_TRUE(Q.is_empty());
}

TEST(TestTQueue, can_push_elements) {
    TQueue<int> Q;

    Q.push(1);
    EXPECT_FALSE(Q.is_empty());

    Q.push(2);
    Q.push(3);
}

TEST(TestTQueue, can_pop_elements) {
    TQueue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);

    EXPECT_EQ(Q.head(), 10);
    Q.pop();
    EXPECT_EQ(Q.head(), 20);

    Q.pop();
    EXPECT_EQ(Q.head(), 30);
}

TEST(TestTQueue, can_handle_fifo_behavior) {
    TQueue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);

    EXPECT_EQ(Q.head(), 1);
    Q.pop();
    EXPECT_EQ(Q.head(), 2);
    Q.pop();
    EXPECT_EQ(Q.head(), 3);
    Q.pop();
    EXPECT_TRUE(Q.is_empty());
}

TEST(TestTQueue, pop_throws_when_empty) {
    TQueue<int> Q;
    EXPECT_THROW(Q.pop(), std::runtime_error);

    Q.push(1);
    Q.pop();
    EXPECT_THROW(Q.pop(), std::runtime_error);
}

TEST(TestTQueue, can_clear_queue) {
    TQueue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);

    EXPECT_FALSE(Q.is_empty());
    Q.clear();
    EXPECT_TRUE(Q.is_empty());
}

TEST(TestTQueue, stress_test) {
    TQueue<int> Q;

    for (int i = 0; i < 1000; i++) {
        Q.push(i);
    }

    for (int i = 0; i < 1000; i++) {
        EXPECT_EQ(Q.head(), i);
        Q.pop();
    }
    EXPECT_TRUE(Q.is_empty());
}

TEST(TestTQueue, can_reuse_after_clear) {
    TQueue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.clear();
    Q.push(10);
    Q.push(20);

    EXPECT_EQ(Q.head(), 10);
    Q.pop();
    EXPECT_EQ(Q.head(), 20);
}