#include <gtest/gtest.h>
#include "../monad_header/monad_adapter.hpp"
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"
#include "../headers/stack.hpp"
#include "../headers/queue.hpp"

TEST(test_monada, test_map)
{
    monad_adapter<array_sequence<int>> arr{array_sequence<int>{1, 2, 3}};
    arr.map([](int x)
            { return x * 2; });
    EXPECT_EQ(arr->get(0), 2);
    EXPECT_EQ(arr->get(1), 4);
    EXPECT_EQ(arr->get(2), 6);

    monad_adapter<list_sequence<int>> lst{list_sequence<int>{1, 2, 3}};
    lst.map([](int x)
            { return x * 2; });
    EXPECT_EQ(lst->get(0), 2);
    EXPECT_EQ(lst->get(1), 4);
    EXPECT_EQ(lst->get(2), 6);

    monad_adapter<stack<int>> stk{stack<int>{1, 2, 3}};
    stk.map([](int x)
            { return x * 2; });
    EXPECT_EQ(stk->top(), 6);
    stk->pop();
    EXPECT_EQ(stk->top(), 4);
    stk->pop();
    EXPECT_EQ(stk->top(), 2);

    monad_adapter<queue<int>> que{queue<int>{1, 2, 3}};
    que.map([](int x)
            { return x * 2; });
    EXPECT_EQ(que->front(), 2);
    EXPECT_EQ(que->back(), 6);
}

TEST(test_monada, test_filter)
{
    monad_adapter<array_sequence<int>> arr{array_sequence<int>{1, 2, 3}};
    arr.filter([](int x)
               { return x % 2 == 0; });
    EXPECT_EQ(arr->get(0), 2);
    EXPECT_EQ(arr->get_length(), 1);

    monad_adapter<list_sequence<int>> lst{list_sequence<int>{1, 2, 3}};
    lst.filter([](int x)
               { return x % 2 == 0; });
    EXPECT_EQ(lst->get(0), 2);
    EXPECT_EQ(lst->get_length(), 1);

    monad_adapter<stack<int>> stk{stack<int>{1, 2, 3}};
    stk.filter([](int x)
               { return x % 2 == 0; });
    EXPECT_EQ(stk->top(), 2);
    EXPECT_EQ(stk->size(), 1);

    monad_adapter<queue<int>> que{queue<int>{1, 2, 3}};
    que.filter([](int x)
               { return x % 2 == 0; });
    EXPECT_EQ(que->front(), 2);
    EXPECT_EQ(que->size(), 1);
}

TEST(test_monada, test_where)
{
    monad_adapter<array_sequence<int>> arr{array_sequence<int>{1, 2, 3}};
    auto new_arr = arr.where([](int x)
                             { return x % 2 == 0; });
    EXPECT_EQ(new_arr->get(0), 0);
    EXPECT_EQ(new_arr->get(1), 1);
    EXPECT_EQ(new_arr->get(2), 0);
    EXPECT_EQ(new_arr->get_length(), 3);

    monad_adapter<list_sequence<int>> lst{list_sequence<int>{1, 2, 3}};
    auto new_lst = lst.where([](int x)
                             { return x % 2 == 0; });
    EXPECT_EQ(new_lst->get(0), 0);
    EXPECT_EQ(new_lst->get(1), 1);
    EXPECT_EQ(new_lst->get(2), 0);
    EXPECT_EQ(new_lst->get_length(), 3);

    monad_adapter<stack<int>> stk{stack<int>{1, 2, 3}};
    auto new_stk = stk.where([](int x)
                             { return x % 2 == 0; });
    EXPECT_EQ(new_stk->top(), 0);
    new_stk->pop();
    EXPECT_EQ(new_stk->top(), 1);
    new_stk->pop();
    EXPECT_EQ(new_stk->top(), 0);
    EXPECT_EQ(new_stk->size(), 1);

    monad_adapter<queue<int>> que{queue<int>{1, 2, 3}};
    auto new_que = que.where([](int x)
                             { return x % 2 == 0; });
    EXPECT_EQ(new_que->front(), 0);
    EXPECT_EQ(new_que->back(), 0);
    new_que->pop();
    EXPECT_EQ(new_que->front(), 1);
    EXPECT_EQ(new_que->size(), 2);
}