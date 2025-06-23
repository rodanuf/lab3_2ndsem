#include <gtest/gtest.h>
#include "../headers/array_sequence.hpp"

TEST(test_array_sequence_iterator, base_constructor_iterator)
{
    array_sequence<int> seq = {42};
    auto it = seq.begin();
    EXPECT_EQ(*it, 42);
}

TEST(test_array_sequence_iterator, copy_constructor_iterator)
{
    int value = 42;
    dynamic_array<int>::array_iterator it(&value);
    array_sequence<int>::as_iterator as_it_one(it);
    array_sequence<int>::as_iterator as_it_two(as_it_one);
    EXPECT_EQ(as_it_two, as_it_one);
}

TEST(test_array_sequence_iterator_operators, pref_operator_increment)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[1]);
    array_sequence<int>::as_iterator as_it_one(it_one);
    array_sequence<int>::as_iterator as_it_two(it_two);
    ASSERT_NE(*as_it_one, *as_it_two); 
    ++as_it_one;
    EXPECT_EQ(*as_it_one, *as_it_two);
    EXPECT_EQ(*as_it_one, 2);
}

TEST(test_array_sequence_iterator_operators, post_operator_increment)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it(&array[0]);
    array_sequence<int>::as_iterator as_it(it);
    auto old_as_it = as_it++;
    EXPECT_EQ(*old_as_it, array[0]);
    EXPECT_EQ(*as_it, array[1]);
}

TEST(test_array_sequence_iterator_operators, pref_operator_decrement)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[1]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    array_sequence<int>::as_iterator as_it_one(it_one);
    array_sequence<int>::as_iterator as_it_two(it_two);
    ASSERT_NE(*as_it_one, *as_it_two);
    --as_it_one;
    EXPECT_EQ(*as_it_one, *as_it_two);
    EXPECT_EQ(*as_it_one, 1);
}

TEST(test_array_sequence_iterator_operators, post_operator_decrement)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it(&array[1]);
    array_sequence<int>::as_iterator as_it(it);
    EXPECT_EQ(*as_it, 2);
    auto old_as_it = as_it--;
    EXPECT_EQ(*old_as_it, array[1]);
    EXPECT_EQ(*as_it, array[0]);    
}

TEST(test_array_sequence_iterator_operators, operator_appropriation)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[1]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    array_sequence<int>::as_iterator as_it_one(it_one);
    array_sequence<int>::as_iterator as_it_two(it_two);
    ASSERT_NE(*as_it_one, *as_it_two);
    as_it_one = as_it_two;
    EXPECT_EQ(*as_it_one, *as_it_two);
}

TEST(test_array_sequence_iterator_operators, operator_increment_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(&array[0]);
    array_sequence<int>::as_iterator as_it(it);
    ASSERT_NE(*as_it, 5);
    as_it + 4;
    EXPECT_EQ(*as_it, 5); 
}

TEST(test_array_sequence_iterator_operators, operator_decrement_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(&array[3]);
    array_sequence<int>::as_iterator as_it(it);
    ASSERT_NE(*as_it, 1);
    as_it - 3;
    EXPECT_EQ(*as_it, 1);
}

TEST(test_array_sequence_iterator_operators, operator_dereferencing)
{
    int value = 42;
    dynamic_array<int>::array_iterator it(&value);
    array_sequence<int>::as_iterator as_it(it);
    EXPECT_EQ(*as_it, 42);
    *as_it = 100;
    EXPECT_EQ(value, 100);
    EXPECT_EQ(*as_it, 100);
}

TEST(test_array_sequence_iterator_operators, operator_accessing_an_element)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(array);
    array_sequence<int>::as_iterator as_it(it);
    EXPECT_EQ(as_it[0], 1);
    EXPECT_EQ(as_it[4], 5);
    as_it[1] = 50;
    EXPECT_EQ(as_it[1], 50);
}

TEST(test_array_sequence_iterator_operators, operator_equality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    dynamic_array<int>::array_iterator it_three(&array[3]);
    array_sequence<int>::as_iterator as_it_one(it_one);
    array_sequence<int>::as_iterator as_it_two(it_two);
    array_sequence<int>::as_iterator as_it_three(it_three);
    EXPECT_TRUE(as_it_one == as_it_two);
    EXPECT_FALSE(as_it_two == as_it_three);    
}

TEST(test_array_sequence_iterator_operators, operator_nonequality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    dynamic_array<int>::array_iterator it_three(&array[3]);
    array_sequence<int>::as_iterator as_it_one(it_one);
    array_sequence<int>::as_iterator as_it_two(it_two);
    array_sequence<int>::as_iterator as_it_three(it_three);
    EXPECT_TRUE(as_it_two != as_it_three);
    EXPECT_FALSE(as_it_one != as_it_two);
}

TEST(test_array_sequence_iterator_operators, method_begin)
{
    array_sequence<int> array = {10, 20, 30};
    array_sequence<int>::as_iterator it = array.begin();
    EXPECT_EQ(*it, 10);
}

TEST(test_array_sequence_iterator_operators, method_end)
{
    array_sequence<int> array = {10, 20, 30};
    array_sequence<int>::const_as_iterator it = array.end();
    EXPECT_EQ(*(it - 1), 30);
}

TEST(test_array_sequence_const_iterator, base_constructor_iterator)
{
    array_sequence<int> seq = {42};
    auto it = seq.begin();
    EXPECT_EQ(*it, 42);
}

TEST(test_array_sequence_const_iterator, copy_constructor_iterator)
{
    int value = 42;
    dynamic_array<int>::array_iterator it(&value);
    array_sequence<int>::const_as_iterator as_it_one(it);
    array_sequence<int>::const_as_iterator as_it_two(as_it_one);
    EXPECT_EQ(as_it_two, as_it_one);
}

TEST(test_array_sequence_const_iterator_operators, pref_operator_increment)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[1]);
    array_sequence<int>::const_as_iterator as_it_one(it_one);
    array_sequence<int>::const_as_iterator as_it_two(it_two);
    ASSERT_NE(*as_it_one, *as_it_two); 
    ++as_it_one;
    EXPECT_EQ(*as_it_one, *as_it_two);
    EXPECT_EQ(*as_it_one, 2);
}

TEST(test_array_sequence_const_iterator_operators, post_operator_increment)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it(&array[0]);
    array_sequence<int>::const_as_iterator as_it(it);
    auto old_as_it = as_it++;
    EXPECT_EQ(*old_as_it, array[0]);
    EXPECT_EQ(*as_it, array[1]);
}

TEST(test_array_sequence_const_iterator_operators, pref_operator_decrement)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[1]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    array_sequence<int>::const_as_iterator as_it_one(it_one);
    array_sequence<int>::const_as_iterator as_it_two(it_two);
    ASSERT_NE(*as_it_one, *as_it_two);
    --as_it_one;
    EXPECT_EQ(*as_it_one, *as_it_two);
    EXPECT_EQ(*as_it_one, 1);
}

TEST(test_array_sequence_const_iterator_operators, post_operator_decrement)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it(&array[1]);
    array_sequence<int>::const_as_iterator as_it(it);
    EXPECT_EQ(*as_it, 2);
    auto old_as_it = as_it--;
    EXPECT_EQ(*old_as_it, array[1]);
    EXPECT_EQ(*as_it, array[0]);    
}

TEST(test_array_sequence_const_iterator_operators, operator_appropriation)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[1]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    array_sequence<int>::const_as_iterator as_it_one(it_one);
    array_sequence<int>::const_as_iterator as_it_two(it_two);
    ASSERT_NE(*as_it_one, *as_it_two);
    as_it_one = as_it_two;
    EXPECT_EQ(*as_it_one, *as_it_two);
}

TEST(test_array_sequence_const_iterator_operators, operator_increment_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(&array[0]);
    array_sequence<int>::const_as_iterator as_it(it);
    ASSERT_NE(*as_it, 5);
    as_it + 4;
    EXPECT_EQ(*as_it, 5); 
}

TEST(test_array_sequence_const_iterator_operators, operator_decrement_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(&array[3]);
    array_sequence<int>::const_as_iterator as_it(it);
    ASSERT_NE(*as_it, 1);
    as_it - 3;
    EXPECT_EQ(*as_it, 1);
}

TEST(test_array_sequence_const_iterator_operators, operator_dereferencing)
{
    int value = 42;
    dynamic_array<int>::array_iterator it(&value);
    array_sequence<int>::const_as_iterator as_it(it);
    EXPECT_EQ(*as_it, 42);
}

TEST(test_array_sequence_const_iterator_operators, operator_accessing_an_element)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(array);
    array_sequence<int>::const_as_iterator as_it(it);
    EXPECT_EQ(as_it[0], 1);
    EXPECT_EQ(as_it[4], 5);
}

TEST(test_array_sequence_const_iterator_operators, operator_equality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    dynamic_array<int>::array_iterator it_three(&array[3]);
    array_sequence<int>::const_as_iterator as_it_one(it_one);
    array_sequence<int>::const_as_iterator as_it_two(it_two);
    array_sequence<int>::const_as_iterator as_it_three(it_three);
    EXPECT_TRUE(as_it_one == as_it_two);
    EXPECT_FALSE(as_it_two == as_it_three);    
}

TEST(test_array_sequence_const_iterator_operators, operator_nonequality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    dynamic_array<int>::array_iterator it_three(&array[3]);
    array_sequence<int>::const_as_iterator as_it_one(it_one);
    array_sequence<int>::const_as_iterator as_it_two(it_two);
    array_sequence<int>::const_as_iterator as_it_three(it_three);
    EXPECT_TRUE(as_it_two != as_it_three);
    EXPECT_FALSE(as_it_one != as_it_two);
}

TEST(test_array_sequence_const_iterator_operators, method_begin)
{
    array_sequence<int> array = {10, 20, 30};
    array_sequence<int>::const_as_iterator it = array.begin();
    EXPECT_EQ(*it, 10);
}

TEST(test_array_sequence_const_iterator_operators, method_end)
{
    array_sequence<int> array = {10, 20, 30};
    array_sequence<int>::const_as_iterator it = array.end();
    EXPECT_EQ(*(it - 1), 30);
}