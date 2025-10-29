// Copyright 2025 xd

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "list.h"


TEST(TestList, can_create_default_list) {
    ASSERT_NO_THROW(List<int> L);
}

TEST(TestList, can_create_copy_list) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);
    ASSERT_NO_THROW(List<int> L2(L));
}

TEST(TestList, is_empty) {
    List<int> L;
    ASSERT_TRUE(L.is_empty());
}

TEST(TestList, is_not_empty_after_push) {
    List<int> L;
    L.push_back(1);
    ASSERT_FALSE(L.is_empty());
}

TEST(TestList, can_push_front) {
    List<int> L;
    ASSERT_NO_THROW(L.push_front(1));
}

TEST(TestList, can_push_back) {
    List<int> L;
    ASSERT_NO_THROW(L.push_back(1));
}

TEST(TestList, can_insert_at_position) {
    List<int> L;
    L.push_back(1);
    L.push_back(3);
    ASSERT_NO_THROW(L.insert(1, 2));
}

TEST(TestList, can_pop_front) {
    List<int> L;
    L.push_back(1);
    ASSERT_NO_THROW(L.pop_front());
}

TEST(TestList, can_pop_back) {
    List<int> L;
    L.push_back(1);
    ASSERT_NO_THROW(L.pop_back());
}

TEST(TestList, can_erase_by_position) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);
    ASSERT_NO_THROW(L.erase(0));
}

TEST(TestList, can_find_element) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);
    ASSERT_NO_THROW(L.find(1));
}

TEST(TestList, can_clear_list) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);
    ASSERT_NO_THROW(L.clear());
}

TEST(TestList, push_front_correctly_adds_element) {
    List<int> L;
    L.push_front(1);
    ASSERT_FALSE(L.is_empty());
    ASSERT_EQ(L.size(), 1);
}

TEST(TestList, push_back_correctly_adds_element) {
    List<int> L;
    L.push_back(1);
    ASSERT_FALSE(L.is_empty());
    ASSERT_EQ(L.size(), 1);
}

TEST(TestList, find_returns_correct_node) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);

    auto node = L.find(2);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 2);
}

TEST(TestList, pop_front_removes_first_element) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);
    L.pop_front();

    ASSERT_EQ(L.size(), 1);
    auto node = L.find(1);
    ASSERT_EQ(node, nullptr);
}

TEST(TestList, clear_removes_all_elements) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);
    L.clear();
    ASSERT_TRUE(L.is_empty());
    ASSERT_EQ(L.size(), 0);
}

TEST(TestList, copy_constructor_creates_equal_list) {
    List<int> L1;
    L1.push_back(1);
    L1.push_back(2);

    List<int> L2(L1);
    ASSERT_FALSE(L2.is_empty());
    ASSERT_EQ(L2.size(), 2);
}

TEST(TestList, iterator_dereference_works) {
    List<int> L;
    L.push_back(42);

    List<int>::Iterator it = L.begin();
    ASSERT_EQ(*it, 42);
}

TEST(TestList, size_returns_correct_count) {
    List<int> L;
    ASSERT_EQ(L.size(), 0);

    L.push_back(1);
    ASSERT_EQ(L.size(), 1);

    L.push_back(2);
    ASSERT_EQ(L.size(), 2);

    L.pop_front();
    ASSERT_EQ(L.size(), 1);
}
TEST(TestList, iterator_read_write_works) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);

    auto it = L.begin();
    ASSERT_EQ(*it, 1);

    *it = 10;
    ASSERT_EQ(*it, 10);

    ++it;
    *it = 20;
    ASSERT_EQ(*it, 20);
}

TEST(TestList, iterator_loop_with_empty_list) {
    List<int> L;
    ASSERT_NO_THROW({
        for (auto it = L.begin(); it != L.end(); ++it) {
            FAIL() << "Should not enter loop with empty list";
        }
        });
}

TEST(TestList, iterator_increment_past_end) {
    List<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(100);

    auto it = L.begin();
    ++it;

    ASSERT_NO_THROW(++it);
    ASSERT_NO_THROW(it++);
}