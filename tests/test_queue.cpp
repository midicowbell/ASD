// Copyright 2025 xd

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "queue.h"
TEST(TestQueueLib, can_create_with_init_constructor) {
	ASSERT_NO_THROW(Queue<int> Q(20));

}