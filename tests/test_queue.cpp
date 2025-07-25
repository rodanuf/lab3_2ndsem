#include <gtest/gtest.h>
#include "../headers/queue.hpp"

TEST(test_queue, basic_constructor)
{
    queue<int> q(new list_sequence<int>());
    EXPECT_EQ(q.size(), 0);
    EXPECT_TRUE(q.is_empty());
}

TEST(test_queue, constructor_by_size)
{
    queue<int> q(new array_sequence<int>(5));
    EXPECT_EQ(q.size(), 5);
    EXPECT_FALSE(q.is_empty());
}

TEST(test_queue, constructor_from_data)
{
    int items[] = {1, 2, 3, 4};
    queue<int> q(new array_sequence<int>(items, 4));
    EXPECT_EQ(q.size(), 4);
    EXPECT_EQ(q.front(), 1);
    EXPECT_EQ(q.back(), 4);
}

TEST(test_queue, constructor_initializer_list)
{
    queue<int> q(new array_sequence<int>({1, 2, 3, 4}));
    EXPECT_EQ(q.size(), 4);
    EXPECT_EQ(q.front(), 1);
    EXPECT_EQ(q.back(), 4);
}

TEST(test_queue, copy_constructor)
{
    queue<int> q1(new list_sequence<int>({1, 2, 3, 4}));
    queue<int> q2(q1);
    EXPECT_EQ(q2.size(), 4);
    EXPECT_EQ(q2.front(), 1);
    EXPECT_EQ(q2.back(), 4);
}

TEST(test_queue_functions, method_push)
{
    queue<int> q(new array_sequence<int>());
    q.push(10);
    EXPECT_EQ(q.size(), 1);
    EXPECT_EQ(q.front(), 10);
    EXPECT_EQ(q.back(), 10);
    q.push(20);
    EXPECT_EQ(q.size(), 2);
    EXPECT_EQ(q.front(), 10);
    EXPECT_EQ(q.back(), 20);
}

TEST(test_queue_functions, method_pop)
{
    queue<int> q(new list_sequence<int>({1, 2, 3}));
    EXPECT_EQ(q.front(), 1);
    q.pop();
    EXPECT_EQ(q.front(), 2);
    q.pop();
    EXPECT_EQ(q.front(), 3);
    q.pop();
    EXPECT_TRUE(q.is_empty());
}

TEST(test_queue_functions, method_front)
{
    queue<int> q(new array_sequence<int>({42}));
    EXPECT_EQ(q.front(), 42);
    q.push(100);
    EXPECT_EQ(q.front(), 42);
}

TEST(test_queue_functions, method_back)
{
    queue<int> q(new list_sequence<int>({42}));
    EXPECT_EQ(q.back(), 42);
    q.push(100);
    EXPECT_EQ(q.back(), 100);
}

TEST(test_queue_functions, method_size)
{
    queue<int> q(new list_sequence<int>());
    EXPECT_EQ(q.size(), 0);
    q.push(1);
    EXPECT_EQ(q.size(), 1);
    q.push(2);
    EXPECT_EQ(q.size(), 2);
    q.pop();
    EXPECT_EQ(q.size(), 1);
}

TEST(test_queue_functions, method_empty)
{
    queue<int> q(new array_sequence<int>());
    EXPECT_TRUE(q.is_empty());
    q.push(1);
    EXPECT_FALSE(q.is_empty());
    q.pop();
    EXPECT_TRUE(q.is_empty());
}
