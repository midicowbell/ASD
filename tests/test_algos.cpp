// Copyright 2024 Marina Usova

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "list.h"
#include <gtest/gtest.h>
#include "../lib_list/list.h"    
#include "algos.h"                

// ======================= fu1 — Заяц и черепаха =======================
TEST(ListCycle_fu1, NoCycle_EmptyList) {
    List<int> list;
    EXPECT_FALSE(fu1(list));
}

TEST(ListCycle_fu1, NoCycle_SingleElement) {
    List<int> list;
    list.push_back(42);
    EXPECT_FALSE(fu1(list));
}

TEST(ListCycle_fu1, NoCycle_LinearList) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_FALSE(fu1(list));
}

TEST(ListCycle_fu1, CycleExists_FromHead) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    auto* first = list.find(1);
    auto* last = list.find(3);
    last->next = first;           

    EXPECT_TRUE(fu1(list));

    last->next = nullptr;         
}

TEST(ListCycle_fu1, CycleExists_InMiddle) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    auto* cycle_node = list.find(20);
    auto* last = list.find(40);
    last->next = cycle_node;     

    EXPECT_TRUE(fu1(list));

    last->next = nullptr;         
}

// ======================= fu2 — Разворот указателей =======================
TEST(ListCycle_fu2, NoCycle) {
    List<int> list;
    list.push_back(5);
    list.push_back(10);
    list.push_back(15);

    EXPECT_FALSE(fu2(list));
}

TEST(ListCycle_fu2, HasCycle) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    auto* cycle_node = list.find(2);
    auto* last = list.find(4);
    last->next = cycle_node;      

    EXPECT_TRUE(fu2(list));
   
}

// ======================= fu3 — Поиск начала цикла =======================
TEST(ListCycle_fu3, NoCycle_ReturnsMinusOne) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(fu3(list), static_cast<size_t>(-1));
}

TEST(ListCycle_fu3, CycleFromHead_ReturnsZero) {
    List<int> list;
    list.push_back(100);
    list.push_back(200);
    list.push_back(300);

    auto* first = list.find(100);
    auto* last = list.find(300);
    last->next = first;          

    EXPECT_EQ(fu3(list), 0);

    last->next = nullptr;        
}

TEST(ListCycle_fu3, CycleInMiddle_CorrectIndex) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    auto* cycle_start = list.find(3);  
    auto* last = list.find(5);
    last->next = cycle_start;          

    EXPECT_EQ(fu3(list), 2);

    last->next = nullptr;             
}

TEST(ListCycle_fu3, CycleAtEnd) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    auto* last = list.find(30);
    auto* target = list.find(20);
    last->next = target;          

    EXPECT_EQ(fu3(list), 1);

    last->next = nullptr;         
}

