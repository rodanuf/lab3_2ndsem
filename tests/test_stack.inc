#include <gtest/gtest.h>
#include "../headers/stack.hpp"

TEST(test_stack_iterator, base_constructor_iterator)
{
    stack<int> st = {42};
    auto it = st.begin();
    EXPECT_EQ(*it, 42);
}

TEST(test_stack_iterator, copy_constructor_iterator)
{
    stack<int> st = {42};
    auto it_one = st.begin();
    auto it_two = it_one;
    EXPECT_EQ(*it_two, 42);
}

TEST(test_stack_iterator_operators, pref_operator_increment)
{
    stack<int> st = {1, 2, 3};
    auto it = st.begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
}

TEST(test_stack_iterator_operators, post_operator_increment)
{
    stack<int> st = {1, 2, 3};
    auto it = st.begin();
    auto old_it = it++;
    EXPECT_EQ(*old_it, 3);
    EXPECT_EQ(*it, 2);
}

TEST(test_stack_iterator_operators, operator_appropriation)
{
    stack<int> st_one = {1, 2, 3};
    stack<int> st_two = {1, 2, 3};
    auto it_one = st_one.begin();
    auto it_two = st_two.begin();
    ++it_one;
    ASSERT_NE(*it_one, *it_two);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_stack_iterator_operators, operator_increment_on)
{
    stack<int> st = {1, 2, 3, 4, 5};
    auto it = st.begin();
    ASSERT_NE(*it, 1);
    it = it + 4;
    EXPECT_EQ(*it, 1);
}

TEST(test_stack_iterator_operators, operator_dereferencing)
{
    stack<int> st = {42};
    auto it = st.begin();
    EXPECT_EQ(*it, 42);
    *it = 100;
    EXPECT_EQ(*it, 100);
}

TEST(test_stack_iterator_operators, operator_equality)
{
    stack<int> st_one = {1, 2, 3, 4, 5};
    stack<int> st_two = {1, 2, 3, 4, 5};
    auto it_one = st_one.begin();
    auto it_two = st_one.begin();
    auto it_three = st_two.begin();
    it_three = it_three + 3;
    EXPECT_TRUE(it_one == it_two);
    EXPECT_FALSE(it_two== it_three);
}

TEST(test_stack_iterator_operators, operator_nonequality)
{
    stack<int> st_one = {1, 2, 3, 4, 5};
    stack<int> st_two = {1, 2, 3, 4, 5};
    auto it_one = st_one.begin();
    auto it_two = st_one.begin();
    auto it_three = st_two.begin();
    it_three = it_three + 3;
    EXPECT_TRUE(it_two != it_three);
    EXPECT_FALSE(it_one != it_two);
}

TEST(test_stack_iterator_functions, method_begin)
{
    stack<int> st = {10, 20, 30};
    auto it = st.begin();
    EXPECT_EQ(*it, 30);
}

TEST(test_stack_iterator_functions, method_end)
{
    stack<int> st = {10, 20, 30};
    auto it = st.end();
    stack<int> empty_st;
    auto empty_it = empty_st.end();
    EXPECT_EQ(it, empty_it);
}

TEST(test_stack_const_iterator, base_constructor_iterator)
{
    stack<int> st = {42};
    auto it = st.cbegin();
    EXPECT_EQ(*it, 42);
}

TEST(test_stack_const_iterator, copy_constructor_iterator)
{
    stack<int> st = {42};
    auto it_one = st.cbegin();
    auto it_two = it_one;
    EXPECT_EQ(*it_two, 42);
}

TEST(test_stack_const_iterator_operators, pref_operator_increment)
{
    stack<int> st = {1, 2, 3};
    auto it = st.cbegin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
}

TEST(test_stack_const_iterator_operators, post_operator_increment)
{
    stack<int> st = {1, 2, 3};
    auto it = st.cbegin();
    auto old_it = it++;
    EXPECT_EQ(*old_it, 3);
    EXPECT_EQ(*it, 2);
}

TEST(test_stack_const_iterator_operators, operator_appropriation)
{
    stack<int> st_one = {1, 2, 3};
    stack<int> st_two = {1, 2, 3};
    auto it_one = st_one.cbegin();
    auto it_two = st_two.cbegin();
    ++it_one;
    ASSERT_NE(*it_one, *it_two);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_stack_const_iterator_operators, operator_increment_on)
{
    stack<int> st = {1, 2, 3, 4, 5};
    auto it = st.cbegin();
    ASSERT_NE(*it, 1);
    it = it + 4;
    EXPECT_EQ(*it, 1);
}

TEST(test_stack_const_iterator_operators, operator_dereferencing)
{
    stack<int> st = {42};
    auto it = st.cbegin();
    EXPECT_EQ(*it, 42);
}

TEST(test_stack_const_iterator_operators, operator_equality)
{
    stack<int> st_one = {1, 2, 3, 4, 5};
    stack<int> st_two = {1, 2, 3, 4, 5};
    auto it_one = st_one.cbegin();
    auto it_two = st_one.cbegin();
    auto it_three = st_two.cbegin();
    it_three = it_three + 3;
    EXPECT_TRUE(it_one == it_two);
    EXPECT_FALSE(it_two == it_three);
}

TEST(test_stack_const_iterator_operators, operator_nonequality)
{
    stack<int> st_one = {1, 2, 3, 4, 5};
    stack<int> st_two = {1, 2, 3, 4, 5};
    auto it_one = st_one.cbegin();
    auto it_two = st_one.cbegin();
    auto it_three = st_two.cbegin();
    it_three = it_three + 3;
    EXPECT_TRUE(it_two != it_three);
    EXPECT_FALSE(it_one != it_two);
}

TEST(test_stack_const_iterator_functions, method_begin)
{
    stack<int> st = {10, 20, 30};
    auto it = st.cbegin();
    EXPECT_EQ(*it, 30);
}

TEST(test_stack_const_iterator_functions, method_end)
{
    stack<int> st = {10, 20, 30};
    auto it = st.cend();
    stack<int> empty_st;
    auto empty_it = empty_st.cend();
    EXPECT_EQ(it, empty_it);
}

TEST(test_stack, basic_constructor)
{
    stack<int> st;
    EXPECT_EQ(st.get_length(), 0);
}

TEST(test_stack, constructor_by_size)
{
    stack<int> st(4);
    EXPECT_EQ(st.get_length(), 4);
}

TEST(test_stack, constructor_from_data)
{
    int items[] = {1, 2, 3, 4};
    stack<int> st(items, 4);
    EXPECT_EQ(st.get_length(), 4);
    EXPECT_EQ(st.get_first(), 4);
    EXPECT_EQ(st.get_last(), 1);
}

TEST(test_stack, constructor_initializer_list)
{
    stack<int> st = {1, 2, 3, 4};
    EXPECT_EQ(st.get_length(), 4);
    EXPECT_EQ(st.get_first(), 4);
    EXPECT_EQ(st.get_last(), 1);
}

TEST(test_stack, copy_constructor)
{
    stack<int> seq = {1, 2, 3, 4};
    stack<int> st(seq);
    EXPECT_EQ(st.get_length(), 4);
    EXPECT_EQ(st.get_first(), 4);
    EXPECT_EQ(st.get_last(), 1);
}

TEST(test_stack_functions, method_get)
{
    stack<int> st = {1, 2, 3, 4};
    stack<int> empty_st;
    EXPECT_THROW(empty_st.get(3), std::out_of_range);
    EXPECT_EQ(st.get(0), 4);
    EXPECT_EQ(st.get(3), 1);
}

TEST(test_stack_functions, method_get_first)
{
    stack<int> st = {1, 2, 3, 4};
    stack<int> empty_st;
    EXPECT_THROW(empty_st.get_first(), std::out_of_range);
    EXPECT_EQ(st.get_first(), 4);
}

TEST(test_stack_functions, method_get_last)
{
    stack<int> st = {1, 2, 3, 4};
    stack<int> empty_st;
    EXPECT_THROW(empty_st.get_last(), std::out_of_range);
    EXPECT_EQ(st.get_last(), 1);
}

TEST(test_stack_functions, method_get_length)
{
    stack<int> st = {1, 2, 3, 4};
    EXPECT_EQ(st.get_length(), 4);
}

TEST(test_stack_functions, method_get_subsequence)
{
    stack<int> st = {1, 2, 3, 4, 5};
    EXPECT_THROW(st.get_subsequence(1, 6), std::out_of_range);
    EXPECT_THROW(st.get_subsequence(-1, 3), std::out_of_range);
    sequence<int>* subst = st.get_subsequence(1, 3);
    ASSERT_NE(subst, nullptr);
    EXPECT_EQ(subst->get_length(), 3);
    EXPECT_EQ(subst->get_first(), 4);
    EXPECT_EQ(subst->get_last(), 2);
}

TEST(test_stack_functions, method_append_element)
{
    stack<int> st = {1, 2, 3, 4};
    st.append_element(5);
    EXPECT_EQ(st.get_last(), 5);
    EXPECT_EQ(st.get_length(), 5);
}

TEST(test_stack_functions, method_prepend_element)
{
    stack<int> st = {1, 2, 3, 4};
    st.prepend_element(0);
    EXPECT_EQ(st.get_first(), 0);
    EXPECT_EQ(st.get_last(), 1);
    EXPECT_EQ(st.get_length(), 5);
}

TEST(test_stack_functions, method_insert_element)
{
    stack<int> st = {1, 2, 4, 5};
    st.insert_element(3, 2);
    EXPECT_EQ(st.get_length(), 5);
    EXPECT_EQ(st.get(2), 3);
}

TEST(test_stack_functions, method_concat)
{
    stack<int> st_one = {1, 2, 3, 4};
    stack<int> st_two = {5, 6, 7, 8};
    sequence<int>* result = st_one.concat(st_two);
    EXPECT_EQ(result->get_length(), 8);
    EXPECT_EQ(result->get_first(), 1);
    EXPECT_EQ(result->get_last(), 8);
    EXPECT_EQ(result->get(4), 5);
}

TEST(test_stack_functions, method_immutable_append_element)
{
    stack<int> st = {1, 2, 3, 4};
    sequence<int>* new_st = st.immutable_append_element(5);
    EXPECT_EQ(new_st->get_last(), 5);
    EXPECT_EQ(new_st->get_length(), 5);
    EXPECT_EQ(st.get_length(), 4);
}

TEST(test_stack_functions, method_immutable_prepend_element)
{
    stack<int> st = {1, 2, 3, 4};
    sequence<int>* new_st = st.immutable_prepend_element(-1);
    EXPECT_EQ(new_st->get_first(), -1);
    EXPECT_EQ(new_st->get_length(), 5);
    EXPECT_EQ(st.get_length(), 4);
}

TEST(test_stack_functions, method_immutable_insert_element)
{
    stack<int> st = {1, 2, 3, 4};
    sequence<int>* new_st = st.immutable_insert_element(5, 2);
    EXPECT_EQ(new_st->get(2), 5);
    EXPECT_EQ(new_st->get_length(), 5);
    EXPECT_EQ(st.get_length(), 4);
}

TEST(test_stack_functions, method_immutable_concat)
{
    stack<int> st_one = {1, 2, 3, 4};
    stack<int> st_two = {5, 6, 7, 8};
    const sequence<int>* result = st_one.immutable_concat(st_two);
    EXPECT_EQ(result->get_length(), 8);
    EXPECT_EQ(result->get_last(), 8);
    EXPECT_EQ(st_one.get_length(), 4);
}

TEST(test_stack_functions, method_clear)
{
    stack<int> st = {1, 2, 3, 4};
    st.clear();
    EXPECT_EQ(st.get_length(), 0);
}