// Copyright 2025 xd

#include <gtest/gtest.h>
#include "list2.h"  

TEST(TestListDoubly, can_create_default_list) {
    ASSERT_NO_THROW(ListDoubly<int> L);
}



TEST(TestListDoubly, is_empty) {
    ListDoubly<int> L;
    ASSERT_TRUE(L.is_empty());
}

TEST(TestListDoubly, is_not_empty_after_push) {
    ListDoubly<int> L;
    L.push_back(1);
    ASSERT_FALSE(L.is_empty());
}

TEST(TestListDoubly, can_push_front) {
    ListDoubly<int> L;
    ASSERT_NO_THROW(L.push_front(1));
}

TEST(TestListDoubly, can_push_back) {
    ListDoubly<int> L;
    ASSERT_NO_THROW(L.push_back(1));
}

TEST(TestListDoubly, can_insert_at_position) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(3);
    ASSERT_NO_THROW(L.insert(1, 2));
}

TEST(TestListDoubly, can_pop_front) {
    ListDoubly<int> L;
    L.push_back(1);
    ASSERT_NO_THROW(L.pop_front());
}

TEST(TestListDoubly, can_pop_back) {
    ListDoubly<int> L;
    L.push_back(1);
    ASSERT_NO_THROW(L.pop_back());
}

TEST(TestListDoubly, can_erase_by_position) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    ASSERT_NO_THROW(L.erase(0));
}

TEST(TestListDoubly, can_find_element) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    ASSERT_NO_THROW(L.find(1));
}

TEST(TestListDoubly, can_clear_list) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    ASSERT_NO_THROW(L.clear());
}

TEST(TestListDoubly, push_front_correctly_adds_element) {
    ListDoubly<int> L;
    L.push_front(1);
    ASSERT_FALSE(L.is_empty());
    ASSERT_EQ(L.size(), 1);
}

TEST(TestListDoubly, push_back_correctly_adds_element) {
    ListDoubly<int> L;
    L.push_back(1);
    ASSERT_FALSE(L.is_empty());
    ASSERT_EQ(L.size(), 1);
}

TEST(TestListDoubly, find_returns_correct_node) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);

    auto node = L.find(2);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 2);
}

TEST(TestListDoubly, pop_front_removes_first_element) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.pop_front();

    ASSERT_EQ(L.size(), 1);
    auto node = L.find(1);
    ASSERT_EQ(node, nullptr);
}

TEST(TestListDoubly, clear_removes_all_elements) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.clear();
    ASSERT_TRUE(L.is_empty());
    ASSERT_EQ(L.size(), 0);
}

TEST(TestListDoubly, iterator_dereference_works) {
    ListDoubly<int> L;
    L.push_back(42);

    ListDoubly<int>::Iterator it = L.begin();
    ASSERT_EQ(*it, 42);
}

TEST(TestListDoubly, size_returns_correct_count) {
    ListDoubly<int> L;
    ASSERT_EQ(L.size(), 0);

    L.push_back(1);
    ASSERT_EQ(L.size(), 1);

    L.push_back(2);
    ASSERT_EQ(L.size(), 2);

    L.pop_front();
    ASSERT_EQ(L.size(), 1);
}

TEST(TestListDoubly, iterator_read_write_works) {
    ListDoubly<int> L;
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

TEST(TestListDoubly, iterator_loop_with_empty_list) {
    ListDoubly<int> L;
    ASSERT_NO_THROW({
        for (auto it = L.begin(); it != L.end(); ++it) {
            FAIL() << "Should not enter loop with empty list";
        }
        });
}

TEST(TestListDoubly, iterator_increment_past_end) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(100);

    auto it = L.begin();
    ++it;

    ASSERT_NO_THROW(++it);
    ASSERT_NO_THROW(it++);
}

TEST(TestListDoubly, iterator_decrement_works) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);

    auto it = L.begin();
    ++it;
    --it; 

    ASSERT_EQ(*it, 1);
}

TEST(TestListDoubly, reverse_iteration_works) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);

    auto it = L.begin();
    ++it;
    ++it; 

    --it; 
    ASSERT_EQ(*it, 2);
}

TEST(TestListDoubly, insert_before_node_works) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(3);

    auto node = L.find(3);
    ASSERT_NE(node, nullptr);

    L.insert(node, 2);

    ASSERT_EQ(L.size(), 3);
    auto it = L.begin();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(*it, 3);
}

TEST(TestListDoubly, erase_middle_node_works) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);

    auto node = L.find(2);
    ASSERT_NE(node, nullptr);

    L.erase(node);

    ASSERT_EQ(L.size(), 2);
    auto it = L.begin();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 3);
}

TEST(TestListDoubly, push_front_maintains_links) {
    ListDoubly<int> L;
    L.push_front(2);
    L.push_front(1);

    ASSERT_EQ(L.size(), 2);
    auto it = L.begin();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 2);
}

TEST(TestListDoubly, push_back_maintains_links) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);

    ASSERT_EQ(L.size(), 2);
    auto it = L.begin();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 2);
}

TEST(TestListDoubly, pop_back_maintains_links) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);

    L.pop_back();

    ASSERT_EQ(L.size(), 2);
    ASSERT_EQ(*L.begin(), 1);

    auto it = L.begin();
    ++it;
    ASSERT_EQ(*it, 2);
}
TEST(TestListDoubly, forward_iteration_traverses_all_elements) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);

    std::vector<int> values;
    for (auto it = L.begin(); it != L.end(); ++it) {
        values.push_back(*it);
    }

    ASSERT_EQ(values.size(), 3);
    ASSERT_EQ(values[0], 1);
    ASSERT_EQ(values[1], 2);
    ASSERT_EQ(values[2], 3);
}

TEST(TestListDoubly, reverse_iteration_traverses_all_elements) {
    ListDoubly<int> L;
    L.push_back(1);
    L.push_back(2);
    L.push_back(3);

    std::vector<int> values;
    for (auto it = L.rbegin(); it != L.rend(); --it) {
        values.push_back(*it);
    }

    ASSERT_EQ(values.size(), 3);
    ASSERT_EQ(values[0], 3);
    ASSERT_EQ(values[1], 2);
    ASSERT_EQ(values[2], 1);
}

TEST(TestListDoubly, iterator_can_modify_elements_during_traversal) {
    ListDoubly<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);

    for (auto it = L.begin(); it != L.end(); ++it) {
        *it += 1;
    }

    auto it = L.begin();
    ASSERT_EQ(*it, 11);
    ++it;
    ASSERT_EQ(*it, 21);
    ++it;
    ASSERT_EQ(*it, 31);
}
