#include <gtest/gtest.h>
#include "../headers/dynamic_array.hpp"

TEST(test_dynamic_array_iterator, base_constructor_iterator)
{
    int value = 42;
    dynamic_array<int>::array_iterator it(&value);
    EXPECT_EQ(*it, value);
}

TEST(test_dynamic_array_iterator, copy_constructor_iterator)
{
    int value = 42;
    dynamic_array<int>::array_iterator it_one(&value);
    dynamic_array<int>::array_iterator it_two(it_one);
    EXPECT_EQ(*it_two, value);
}

TEST(test_dynamic_array_iterator_operators, pref_operator_increment)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[1]);
    ASSERT_NE(*it_one, *it_two); 
    ++it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 2);
}

TEST(test_dynamic_array_iterator_operators, post_operator_increment)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it(&array[0]);
    auto old_it = it++;
    EXPECT_EQ(*old_it, array[0]);
    EXPECT_EQ(*it, array[1]);
}

TEST(test_dynamic_array_iterator_operators, pref_operator_decrement)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[1]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    ASSERT_NE(*it_one, *it_two);
    --it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 1);
}

TEST(test_dynamic_array_iterator_operators, post_operator_decrement)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it(&array[1]);
    EXPECT_EQ(*it, 2);
    auto old_it = it--;
    EXPECT_EQ(*old_it, array[1]);
    EXPECT_EQ(*it, array[0]);

}

TEST(test_dynamic_array_iterator_operators, operator_appropriation)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::array_iterator it_one(&array[1]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    ASSERT_NE(*it_one, *it_two);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_dynamic_array_iterator_operators, operator_increment_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(&array[0]);
    ASSERT_NE(*it, 5);
    it + 4;
    EXPECT_EQ(*it, 5);
}

TEST(test_dynamic_array_iterator_operators, operator_decrement_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(&array[3]);
    ASSERT_NE(*it, 1);
    it - 3;
    EXPECT_EQ(*it, 1);
}

TEST(test_dynamic_array_iterator_operators, operator_dereferencing)
{
    int value = 42;
    dynamic_array<int>::array_iterator it(&value);
    EXPECT_EQ(*it, 42);
    *it = 100;
    EXPECT_EQ(value, 100);
    EXPECT_EQ(*it, 100);
}

TEST(test_dynamic_array_iterator_operators, operator_accessing_an_element)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(array);
    EXPECT_EQ(it[0], 1);
    EXPECT_EQ(it[4], 5);
    it[1] = 50;
    EXPECT_EQ(it[1], 50);
}

TEST(test_dynamic_array_iterator_operators, operator_equality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    dynamic_array<int>::array_iterator it_three(&array[3]);
    EXPECT_TRUE(it_one == it_two);
    EXPECT_FALSE(it_two == it_three);
}

TEST(test_dynamic_array_iterator_operators, operator_nonequality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    dynamic_array<int>::array_iterator it_three(&array[3]);
    EXPECT_TRUE(it_two != it_three);
    EXPECT_FALSE(it_one != it_two);
}