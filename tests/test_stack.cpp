#include <gtest/gtest.h>
#include "../headers/stack.hpp"

TEST(test_stack, basic_constructor)
{
    stack<int> st(new list_sequence<int>());
    EXPECT_EQ(st.size(), 0);
    EXPECT_TRUE(st.is_empty());
}

TEST(test_stack, constructor_by_size)
{
    stack<int> st(new array_sequence<int>(5));
    EXPECT_EQ(st.size(), 5);
    EXPECT_FALSE(st.is_empty());
}

TEST(test_stack, constructor_from_data)
{
    int items[] = {1, 2, 3, 4};
    stack<int> st(new array_sequence<int>(items, 4));
    EXPECT_EQ(st.size(), 4);
    EXPECT_EQ(st.top(), 4);
}

TEST(test_stack, constructor_initializer_list)
{
    stack<int> st(new array_sequence<int>({1, 2, 3, 4}));
    EXPECT_EQ(st.size(), 4);
    EXPECT_EQ(st.top(), 4);
}

TEST(test_stack, copy_constructor)
{
    stack<int> st1(new list_sequence<int>({1, 2, 3, 4}));
    stack<int> st2(st1);
    EXPECT_EQ(st2.size(), 4);
    EXPECT_EQ(st2.top(), 4);
}

TEST(test_stack_functions, method_push)
{
    stack<int> st(new array_sequence<int>());
    st.push(10);
    EXPECT_EQ(st.size(), 1);
    EXPECT_EQ(st.top(), 10);
    st.push(20);
    EXPECT_EQ(st.size(), 2);
    EXPECT_EQ(st.top(), 20);
}

TEST(test_stack_functions, method_pop)
{
    stack<int> st(new list_sequence<int>({1, 2, 3}));
    EXPECT_EQ(st.top(), 3);
    st.pop();
    EXPECT_EQ(st.top(), 2);
    st.pop();
    EXPECT_EQ(st.top(), 1);
    st.pop();
    EXPECT_TRUE(st.is_empty());
}

TEST(test_stack_functions, method_top)
{
    stack<int> st(new array_sequence<int>({42}));
    EXPECT_EQ(st.top(), 42);
    st.push(100);
    EXPECT_EQ(st.top(), 100);
}

TEST(test_stack_functions, method_size)
{
    stack<int> st(new list_sequence<int>());
    EXPECT_EQ(st.size(), 0);
    st.push(1);
    EXPECT_EQ(st.size(), 1);
    st.push(2);
    EXPECT_EQ(st.size(), 2);
    st.pop();
    EXPECT_EQ(st.size(), 1);
}

TEST(test_stack_functions, method_empty)
{
    stack<int> st(new array_sequence<int>());
    EXPECT_TRUE(st.is_empty());
    st.push(1);
    EXPECT_FALSE(st.is_empty());
    st.pop();
    EXPECT_TRUE(st.is_empty());
}
