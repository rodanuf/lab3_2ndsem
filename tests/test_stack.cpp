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

TEST(test_stack_functions, method_map)
{
    stack<int> st(new list_sequence<int>({1, 2, 3}));
    auto square = [](int x)
    { return x * x; };
    st.map(square);
    EXPECT_EQ(st.top(), 9);
    st.pop();
    EXPECT_EQ(st.top(), 4);
    st.pop();
    EXPECT_EQ(st.top(), 1);
}

TEST(test_stack_functions, method_where)
{
    stack<int> st(new array_sequence<int>({1, 2, 3, 4, 5}));
    auto is_even = [](int x)
    { return x % 2 == 0; };
    stack<int> *filtered = st.where(is_even);
    EXPECT_EQ(filtered->size(), 2);
    EXPECT_EQ(filtered->top(), 4);
    filtered->pop();
    EXPECT_EQ(filtered->top(), 2);
    delete filtered;
}

TEST(test_stack_functions, method_reduce)
{
    stack<int> st(new list_sequence<int>({1, 2, 3, 4}));
    auto sum = [](int a, int b)
    { return a + b; };
    int result = st.reduce(sum, 0);
    EXPECT_EQ(result, 10);
}

TEST(test_stack_functions, method_immutable_map)
{
    stack<int> st(new array_sequence<int>({1, 2, 3}));
    auto square = [](int x)
    { return x * x; };
    stack<int> *new_stack = st.immutable_map(square);
    EXPECT_EQ(new_stack->size(), 3);
    EXPECT_EQ(new_stack->top(), 9);
    new_stack->pop();
    EXPECT_EQ(new_stack->top(), 4);
    delete new_stack;
    EXPECT_EQ(st.top(), 3);
}