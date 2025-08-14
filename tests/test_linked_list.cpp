#include <gtest/gtest.h>
#include "../headers/linked_list.hpp"

TEST(test_linked_list_node, node_constructor)
{
    linked_list<int> list = {42};
    EXPECT_EQ(list.get_first(), 42);
    EXPECT_EQ(list.get_last(), 42);
}

TEST(test_linked_list_iterator, base_constructor_iterator)
{
    linked_list<int> list = {42};
    auto it = list.begin();
    EXPECT_EQ((*it)->element, 42);
}

TEST(test_linked_list_iterator, copy_constructor_iterator)
{
    linked_list<int> list = {42};
    auto it_one = list.begin();
    auto it_two = it_one;
    EXPECT_EQ((*it_two)->element, 42);
}

TEST(test_linked_list_iterator_operators, pref_operator_increment)
{
    linked_list<int> list = {1, 2, 3};
    auto it_one = list.begin();
    EXPECT_EQ((*it_one)->element, 1);
    ++it_one;
    EXPECT_EQ((*it_one)->element, 2);
    ++it_one;
    EXPECT_EQ((*it_one)->element, 3);
    auto it_two = list.begin();
    EXPECT_NE(*it_one, *it_two);
}

TEST(test_linked_list_iterator_operators, post_operator_increment)
{
    linked_list<int> list = {1, 2, 3};
    auto it = list.begin();
    auto old_it = it++;
    EXPECT_EQ((*old_it)->element, 1);
    EXPECT_EQ((*it)->element, 2);
}

TEST(test_linked_list_iterator_operators, pref_operator_decrement)
{
    linked_list<int> list = {1, 2, 3};
    auto it_one = list.begin();
    ++it_one;
    EXPECT_EQ((*it_one)->element, 2);
    --it_one;
    EXPECT_EQ((*it_one)->element, 1);
    ++it_one;
    ++it_one;
    --it_one;
    EXPECT_EQ((*it_one)->element, 2);
    auto it_two = list.begin();
    EXPECT_NE(*it_one, *it_two);
}

TEST(test_linked_list_iterator_operators, post_operator_decrement)
{
    linked_list<int> list = {1, 2, 3};
    auto it = list.begin();
    ++it;
    EXPECT_EQ((*it)->element, 2);
    auto old_it = it--;
    EXPECT_EQ((*old_it)->element, 2);
    EXPECT_EQ((*it)->element, 1);
}

TEST(test_linked_list_iterator_operators, operator_appropriation)
{
    linked_list<int> list_one = {1, 2, 3};
    linked_list<int> list_two = {4, 5, 6};
    auto it_one = list_one.begin();
    auto it_two = list_two.begin();
    ++it_one;
    ASSERT_NE((*it_one)->element, (*it_two)->element);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_linked_list_iterator_operators, operator_increment_on)
{
    linked_list<int> list = {1, 2, 3, 4, 5};
    auto it = list.begin();
    ASSERT_NE((*it)->element, 5);
    it = it + 4;
    EXPECT_EQ((*it)->element, 5);
}

TEST(test_linked_list_iterator_operators, operator_decrement_on)
{
    linked_list<int> list = {1, 2, 3, 4, 5};
    auto it = list.begin();
    it = it + 3;
    ASSERT_NE((*it)->element, 1);
    it = it - 3;
    EXPECT_EQ((*it)->element, 1);
}

TEST(test_linked_list_iterator_operators, operator_dereferencing)
{
    linked_list<int> list = {42};
    auto it = list.begin();
    EXPECT_EQ((*it)->element, 42);
    (*it)->element = 100;
    EXPECT_EQ((*it)->element, 100);
}

TEST(test_linked_list_iterator_operators, operator_equality)
{
    linked_list<int> list = {1, 2, 3, 4, 5};
    auto it_one = list.cbegin();
    auto it_two = list.cbegin();
    it_two = it_two + 3;
    EXPECT_FALSE(it_two == it_one);
}

TEST(test_linked_list_iterator_operators, operator_nonequality)
{
    linked_list<int> list = {1, 2, 3, 4, 5};
    auto it_one = list.cbegin();
    auto it_two = list.cbegin();
    it_two = it_two + 3;
    EXPECT_TRUE(it_two != it_one);
}

TEST(test_linked_list_iterator_functions, method_begin)
{
    linked_list<int> list = {10, 20, 30};
    auto it = list.begin();
    EXPECT_EQ((*it)->element, 10);
}

TEST(test_linked_list_iterator_functions, method_end)
{
    linked_list<int> list = {10, 20, 30};
    auto it = list.end();
    EXPECT_EQ(*it, nullptr);
}

TEST(test_linked_list_const_iterator, base_constructor_iterator)
{
    linked_list<int> list = {42};
    auto it = list.cbegin();
    EXPECT_EQ((*it)->element, 42);
}

TEST(test_linked_list_const_iterator, copy_constructor_iterator)
{
    linked_list<int> list = {42};
    auto it_one = list.cbegin();
    auto it_two = it_one;
    EXPECT_EQ((*it_two)->element, 42);
}

TEST(test_linked_list_const_iterator_operators, pref_operator_increment)
{
    linked_list<int> list_one = {1, 2, 3};
    linked_list<int> list_two = {1, 2, 3};
    auto it_one = list_one.cbegin();
    auto it_two = list_two.cbegin();
    ++it_two;
    ASSERT_NE((*it_one)->element, (*it_two)->element);
    ++it_one;
    EXPECT_EQ((*it_one)->element, (*it_two)->element);
    EXPECT_EQ((*it_one)->element, 2);
}

TEST(test_linked_list_const_iterator_operators, post_operator_increment)
{
    linked_list<int> list = {1, 2, 3};
    auto it = list.cbegin();
    auto old_it = it++;
    EXPECT_EQ((*old_it)->element, 1);
    EXPECT_EQ((*it)->element, 2);
}

TEST(test_linked_list_const_iterator_operators, pref_operator_decrement)
{
    linked_list<int> list_one = {1, 2, 3};
    linked_list<int> list_two = {1, 2, 3};
    auto it_one = list_one.cbegin();
    ++it_one;
    auto it_two = list_two.cbegin();
    ASSERT_NE((*it_one)->element, (*it_two)->element);
    --it_one;
    EXPECT_EQ((*it_one)->element, (*it_two)->element);
    EXPECT_EQ((*it_one)->element, 1);
}

TEST(test_linked_list_const_iterator_operators, post_operator_decrement)
{
    linked_list<int> list = {1, 2, 3};
    auto it = list.cbegin();
    ++it;
    EXPECT_EQ((*it)->element, 2);
    auto old_it = it--;
    EXPECT_EQ((*old_it)->element, 2);
    EXPECT_EQ((*it)->element, 1);
}

TEST(test_linked_list_const_iterator_operators, operator_appropriation)
{
    linked_list<int> list_one = {1, 2, 3};
    linked_list<int> list_two = {1, 2, 3};
    auto it_one = list_one.cbegin();
    auto it_two = list_two.cbegin();
    ++it_one;
    ASSERT_NE((*it_one)->element, (*it_two)->element);
    it_one = it_two;
    EXPECT_EQ((*it_one)->element, (*it_two)->element);
}

TEST(test_linked_list_const_iterator_operators, operator_increment_on)
{
    linked_list<int> list = {1, 2, 3, 4, 5};
    auto it = list.cbegin();
    ASSERT_NE((*it)->element, 5);
    it = it + 4;
    EXPECT_EQ((*it)->element, 5);
}

TEST(test_linked_list_const_iterator_operators, operator_decrement_on)
{
    linked_list<int> list = {1, 2, 3, 4, 5};
    auto it = list.cbegin();
    it = it + 3;
    ASSERT_NE((*it)->element, 1);
    it = it - 3;
    EXPECT_EQ((*it)->element, 1);
}

TEST(test_linked_list_const_iterator_operators, operator_dereferencing)
{
    linked_list<int> list = {42};
    auto it = list.cbegin();
    EXPECT_EQ((*it)->element, 42);
}

TEST(test_linked_list_const_iterator_operators, operator_equality)
{
    linked_list<int> list = {1, 2, 3, 4, 5};
    auto it_one = list.cbegin();
    auto it_two = list.cbegin();
    it_two = it_two + 3;
    EXPECT_FALSE(it_two == it_one);
}

TEST(test_linked_list_const_iterator_operators, operator_nonequality)
{
    linked_list<int> list = {1, 2, 3, 4, 5};
    auto it_one = list.cbegin();
    auto it_two = list.cbegin();
    it_two = it_two + 3;
    EXPECT_TRUE(it_two != it_one);
}

TEST(test_linked_list_const_iterator_functions, method_begin)
{
    linked_list<int> list = {10, 20, 30};
    auto it = list.cbegin();
    EXPECT_EQ((*it)->element, 10);
}

TEST(test_linked_list_const_iterator_functions, method_end)
{
    linked_list<int> list = {10, 20, 30};
    auto it = list.cend();
    EXPECT_EQ(*it, nullptr);
}

TEST(test_linked_list, basic_constructor)
{
    linked_list<int> list;
    EXPECT_EQ(list.get_length(), 0);
}

TEST(test_linked_list, constructor_by_size)
{
    linked_list<int> list(4);
    EXPECT_EQ(list.get_length(), 4);
}

TEST(test_linked_list, constructor_from_data)
{
    int items[] = {1, 2, 3, 4};
    linked_list<int> list(items, 4);
    EXPECT_EQ(list.get_length(), 4);
    EXPECT_EQ(list.get_first(), 1);
    EXPECT_EQ(list.get_last(), 4);
}

TEST(test_linked_list, constructor_initializer_list)
{
    linked_list<int> list = {1, 2, 3, 4};
    EXPECT_EQ(list.get_length(), 4);
    EXPECT_EQ(list.get_first(), 1);
    EXPECT_EQ(list.get_last(), 4);
}

TEST(test_linked_list, copy_constructor)
{
    linked_list<int> list_one = {1, 2, 3, 4};
    linked_list<int> list_two(list_one);
    EXPECT_EQ(list_two.get_length(), 4);
    EXPECT_EQ(list_two.get_first(), 1);
    EXPECT_EQ(list_two.get_last(), 4);
}

TEST(test_linked_list_functions, method_get)
{
    linked_list<int> list = {1, 2, 3, 4};
    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(2), 3);
}

TEST(test_linked_list_functions, method_get_first)
{
    linked_list<int> list = {1, 2, 3, 4};
    EXPECT_EQ(list.get_first(), 1);
}

TEST(test_linked_list_functions, method_get_last)
{
    linked_list<int> list = {1, 2, 3, 4};
    EXPECT_EQ(list.get_last(), 4);
}

TEST(test_linked_list_functions, method_get_length)
{
    linked_list<int> list = {1, 2, 3, 4};
    EXPECT_EQ(list.get_length(), 4);
}

TEST(test_linked_list_functions, method_append_element)
{
    linked_list<int> list = {1, 2, 3, 4};
    list.append_element(5);
    EXPECT_EQ(list.get_last(), 5);
    EXPECT_EQ(list.get_length(), 5);
}

TEST(test_linked_list_functions, method_prepend_element)
{
    linked_list<int> list = {1, 2, 3, 4};
    list.prepend_element(-1);
    EXPECT_EQ(list.get_first(), -1);
    EXPECT_EQ(list.get_length(), 5);
}

TEST(test_linked_list_functions, method_insert_element)
{
    linked_list<int> list = {1, 2, 4, 5};
    list.insert_element(3, 2);
    EXPECT_EQ(list.get(2), 3);
    EXPECT_EQ(list.get_length(), 5);
}

TEST(test_linked_list_functions, method_remove_at)
{
    int a = 42;
    linked_list<int> list = {1, 2, 3, 5};
    list.remove_at(3);
    EXPECT_EQ(list.get_last(), 3);
    EXPECT_EQ(list.get_length(), 3);
    list.remove_at(0);
    EXPECT_EQ(list.get_first(), 2);
    EXPECT_EQ(list.get_length(), 2);
}

TEST(test_linked_list_functions, method_clear)
{
    linked_list<int> list = {1, 2, 3, 4};
    list.clear();
    EXPECT_EQ(list.get_length(), 0);
}