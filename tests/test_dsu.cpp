// Copyright 2024 Marina Usova

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "dsu.h"
#include "algos.h"


TEST(TestDSU, can_create_with_init_const) {        // создание с начальным размером
	DSU dsu(10);
	EXPECT_EQ(dsu.size(), 10);
}
TEST(TestDSU, unite_two_disjoint_sets) {           // объединение двух непересекающихся множеств
    DSU dsu(5);
    dsu.unite(1, 2);
    EXPECT_EQ(dsu.find(1), dsu.find(2));
}
TEST(TestDSU, unite_already_connected) {           // объединение уже связанных элементов
    DSU dsu(5);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    dsu.unite(1, 3); 
    EXPECT_EQ(dsu.find(1), dsu.find(3));
}
TEST(TestDSU, unite_equal_rank_sets) {             // объединение множеств с равным рангом
    DSU dsu(5);
    dsu.unite(0, 1);
	dsu.unite(2, 3);
    dsu.unite(1, 3);
    EXPECT_EQ(dsu.find(0), dsu.find(3));
}
TEST(TestDSU, find_self_root) {                    // поиск корня самого себя
    DSU dsu(5);
    EXPECT_EQ(dsu.find(3), 3);
}
TEST(TestDSU, find_min_index) {                    // поиск минимального индекса
    DSU dsu(5);
    EXPECT_EQ(dsu.find(0), 0);
}
TEST(TestDSU, find_max_index) {                    // поиск максимального индекса
    DSU dsu(5);
    EXPECT_EQ(dsu.find(4), 4);
}
TEST(TestDSU, path_compression_effectiveness) {    // эффективность сжатия пути
    DSU dsu(6);
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    EXPECT_EQ(dsu.find(3), dsu.find(0));
}
<<<<<<< HEAD
TEST(TestCountIslands, Chessboard10x10) {
    const int SIZE = 10;
    std::vector<std::vector<int>> grid(SIZE, std::vector<int>(SIZE));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = (i + j) % 2;
        }
    }

    EXPECT_EQ(count_islands(grid), 50); // 100 клеток / 2 = 50 островов
}

TEST(TestCountIslands, ClassicExample) {
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    EXPECT_EQ(count_islands(grid), 3);
}
=======
>>>>>>> 3ccd0a3eba53b05e0f2aa407d8772fb5d04128fe
