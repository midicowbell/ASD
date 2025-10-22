#include <gtest/gtest.h>
#include "../lib_easy_example/easy_example.h"
#include "stack.h"
#include "algorithms.h"

TEST(TestAlg, a_lot_of_parentheses) {
	EXPECT_FALSE(check_brackets(")()()(())()((()()({}{[]}{}{}{}{{}{][][][][])(()())][][[]{{{{{{]][][][][}}}"));
    EXPECT_TRUE(check_brackets("(())()()()()(){{}}[[[]]][][]"));
}
TEST(TestAlg, asdas) {
    EXPECT_FALSE(check_brackets("}"));
    
}
TEST(TestAlg, nothing) {
	EXPECT_TRUE(check_brackets(""));
}
TEST(TestAlg, not_closed) {
    EXPECT_FALSE(check_brackets("(()"));
    EXPECT_FALSE(check_brackets("({}"));
    EXPECT_FALSE(check_brackets("[[]"));
    EXPECT_FALSE(check_brackets("{{}"));
    EXPECT_FALSE(check_brackets("()("));
    EXPECT_FALSE(check_brackets("{}["));
    EXPECT_FALSE(check_brackets("[]{"));
    EXPECT_FALSE(check_brackets("({[]}"));
}
TEST(TestAlg, not_open) {
    EXPECT_FALSE(check_brackets(")[[][][]]]][{{}{[)))"));
    EXPECT_FALSE(check_brackets("]]]]]]]]]]]"));
    EXPECT_FALSE(check_brackets("[]]]]"));
    EXPECT_FALSE(check_brackets("{}]]]]"));
    EXPECT_FALSE(check_brackets(")("));
    EXPECT_FALSE(check_brackets("}["));
    EXPECT_FALSE(check_brackets("]{"));
    EXPECT_FALSE(check_brackets("]})"));
}