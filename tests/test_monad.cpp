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

TEST(test_monada, test_reduce)
{
    monad_adapter<array_sequence<int>> arr{array_sequence<int>{1, 2, 3}};
    auto new_arr = arr.reduce([](int x, int y)
                               { return x + y; }, 0);
    EXPECT_EQ(new_arr, 6);

    monad_adapter<list_sequence<int>> lst{list_sequence<int>{1, 2, 3}};
    auto new_lst = lst.reduce([](int x, int y)
                               { return x + y; }, 0);
    EXPECT_EQ(new_lst, 6);

    monad_adapter<stack<int>> stk{stack<int>{1, 2, 3}};
    auto new_stk = stk.reduce([](int x, int y)
                               { return x + y; }, 0);
    EXPECT_EQ(new_stk, 6);

    monad_adapter<queue<int>> que{queue<int>{1, 2, 3}};
    auto new_que = que.reduce([](int x, int y)
                               { return x + y; }, 0);   
    EXPECT_EQ(new_que, 6);
}

TEST(test_monada, test_immutable_map)
{
    monad_adapter<array_sequence<int>> arr{array_sequence<int>{1, 2, 3}};
    auto new_arr = arr.immutable_map([](int x)
                           { return x * 2; });
    EXPECT_EQ(new_arr->get(0), 2);
    EXPECT_EQ(new_arr->get(1), 4);
    EXPECT_EQ(new_arr->get(2), 6);

    monad_adapter<list_sequence<int>> lst{list_sequence<int>{1, 2, 3}};
    auto new_lst = lst.immutable_map([](int x)
                           { return x * 2; });
    EXPECT_EQ(new_lst->get(0), 2);
    EXPECT_EQ(new_lst->get(1), 4);
    EXPECT_EQ(new_lst->get(2), 6);

    monad_adapter<stack<int>> stk{stack<int>{1, 2, 3}};
    auto new_stk = stk.immutable_map([](int x)
                           { return x * 2; });
    EXPECT_EQ(new_stk->top(), 6);
    new_stk->pop();
    EXPECT_EQ(new_stk->top(), 4);
    new_stk->pop();
    EXPECT_EQ(new_stk->top(), 2);

    monad_adapter<queue<int>> que{queue<int>{1, 2, 3}};
    auto new_que = que.immutable_map([](int x)
                           { return x * 2; });
    EXPECT_EQ(new_que->front(), 2);
    EXPECT_EQ(new_que->back(), 6);
    new_que->pop();
    EXPECT_EQ(new_que->front(), 4);

    EXPECT_EQ(arr->get(0), 1);
}

TEST(test_monada, test_immutable_filter)
{
    monad_adapter<array_sequence<int>> arr{array_sequence<int>{1, 2, 3}};
    auto new_arr = arr.immutable_filter([](int x)
                           { return x % 2 == 0; });
    EXPECT_EQ(new_arr->get(0), 2);
    EXPECT_EQ(new_arr->get_length(), 1);

    monad_adapter<list_sequence<int>> lst{list_sequence<int>{1, 2, 3}};
    auto new_lst = lst.immutable_filter([](int x)
                           { return x % 2 == 0; });
    EXPECT_EQ(new_lst->get(0), 2);
    EXPECT_EQ(new_lst->get_length(), 1);

    monad_adapter<stack<int>> stk{stack<int>{1, 2, 3}};
    auto new_stk = stk.immutable_filter([](int x)
                           { return x % 2 == 0; });
    EXPECT_EQ(new_stk->top(), 2);
    EXPECT_EQ(new_stk->size(), 1);

    monad_adapter<queue<int>> que{queue<int>{1, 2, 3}};
    auto new_que = que.immutable_filter([](int x)
                           { return x % 2 == 0; });
    EXPECT_EQ(new_que->front(), 2);
    EXPECT_EQ(new_que->size(), 1);
}

TEST(test_monada, test_functional_pipeline)
{
     monad_adapter<array_sequence<int>> arr{array_sequence<int>{1, 2, 3, 4, 5, 6}};
     auto new_arr = arr>>transform([](int x)
                                { return x * 2; })>>keep([](int x)
                                                        { return x % 2 == 0; })>>keep([](int x)
                                                                                        { return x > 4; });

     EXPECT_EQ(new_arr->get(1), 8);
     EXPECT_EQ(new_arr->get(2), 10);
     EXPECT_EQ(new_arr->get_length(), 4);
}