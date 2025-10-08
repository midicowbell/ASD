// Copyright 2025 xd

#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "stack.h"

TEST(TestStackLib, can_create_with_init_constructor) {
	ASSERT_NO_THROW(Stack<int> S(20));

}
