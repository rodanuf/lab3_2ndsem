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
    it = it + 4;
    EXPECT_EQ(*it, 5);
}

TEST(test_dynamic_array_iterator_operators, operator_decrement_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it(&array[3]);
    ASSERT_NE(*it, 1);
    it = it - 3;
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

TEST(test_dynamic_array_iterator_functions, method_begin)
{
    dynamic_array<int> array = {10, 20, 30};
    auto it = array.begin();
    EXPECT_EQ(*it, 10);
}

TEST(test_dynamic_array_iterator_functions, method_end)
{
    dynamic_array<int> array = {10, 20, 30};
    auto it = array.end();
    EXPECT_EQ(*(it - 1), 30);
}

TEST(test_dynamic_const_array_iterator, base_constructor_iterator)
{
    int value = 42;
    dynamic_array<int>::const_array_iterator it(&value);
    EXPECT_EQ(*it, value);
}

TEST(test_dynamic_const_array_iterator, copy_constructor_iterator)
{
    int value = 42;
    dynamic_array<int>::const_array_iterator it_one(&value);
    dynamic_array<int>::const_array_iterator it_two(it_one);
    EXPECT_EQ(*it_two, value);
}

TEST(test_dynamic_const_array_iterator_operators, pref_operator_increment)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::const_array_iterator it_one(&array[0]);
    dynamic_array<int>::const_array_iterator it_two(&array[1]);
    ASSERT_NE(*it_one, *it_two); 
    ++it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 2);
}

TEST(test_dynamic_const_array_iterator_operators, post_operator_increment)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::const_array_iterator it(&array[0]);
    auto old_it = it++;
    EXPECT_EQ(*old_it, array[0]);
    EXPECT_EQ(*it, array[1]);
}

TEST(test_dynamic_const_array_iterator_operators, pref_operator_decrement)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::const_array_iterator it_one(&array[1]);
    dynamic_array<int>::const_array_iterator it_two(&array[0]);
    ASSERT_NE(*it_one, *it_two);
    --it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 1);
}

TEST(test_dynamic_const_array_iterator_operators, post_operator_decrement)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::const_array_iterator it(&array[1]);
    EXPECT_EQ(*it, 2);
    auto old_it = it--;
    EXPECT_EQ(*old_it, array[1]);
    EXPECT_EQ(*it, array[0]);

}

TEST(test_dynamic_const_array_iterator_operators, operator_appropriation)
{
    int array[] = {1, 2, 3};
    dynamic_array<int>::const_array_iterator it_one(&array[1]);
    dynamic_array<int>::const_array_iterator it_two(&array[0]);
    ASSERT_NE(*it_one, *it_two);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_dynamic_const_array_iterator_operators, operator_increment_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::const_array_iterator it(&array[0]);
    ASSERT_NE(*it, 5);
    it = it + 4;
    EXPECT_EQ(*it, 5);
}

TEST(test_dynamic_const_array_iterator_operators, operator_decrement_on)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::const_array_iterator it(&array[3]);
    ASSERT_NE(*it, 1);
    it = it - 3;
    EXPECT_EQ(*it, 1);
}

TEST(test_dynamic_const_array_iterator_operators, operator_dereferencing)
{
    int value = 42;
    dynamic_array<int>::const_array_iterator it(&value);
    EXPECT_EQ(*it, 42);
    static_assert(std::is_same_v<decltype(*it), const int&>);
}

TEST(test_dynamic_const_array_iterator_operators, operator_accessing_an_element)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::const_array_iterator it(array);
    EXPECT_EQ(it[0], 1);
    EXPECT_EQ(it[4], 5);
    static_assert(std::is_same_v<decltype(it[0]), const int&>);
}

TEST(test_dynamic_const_array_iterator_operators, operator_equality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::const_array_iterator it_one(&array[0]);
    dynamic_array<int>::const_array_iterator it_two(&array[0]);
    dynamic_array<int>::const_array_iterator it_three(&array[3]);
    EXPECT_TRUE(it_one == it_two);
    EXPECT_FALSE(it_two == it_three);
}

TEST(test_dynamic_const_array_iterator_operators, operator_nonequality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::const_array_iterator it_one(&array[0]);
    dynamic_array<int>::const_array_iterator it_two(&array[0]);
    dynamic_array<int>::const_array_iterator it_three(&array[3]);
    EXPECT_TRUE(it_two != it_three);
    EXPECT_FALSE(it_one != it_two);
}

TEST(test_dynamic_const_array_iterator_functions, method_begin)
{
    dynamic_array<int> array = {10, 20, 30};
    auto it = array.cbegin();
    EXPECT_EQ(*it, 10);
}

TEST(test_dynamic_const_array_iterator_functions, method_end)
{
    dynamic_array<int> array = {10, 20, 30};
    auto it = array.cend();
    EXPECT_EQ(*(it - 1), 30);
}

TEST(test_dynamic_array, basic_constructor)
{
    dynamic_array<int> array;
    EXPECT_EQ(array.get_length(), 0);
}

TEST(test_dynamic_array, constructor_by_size)
{
    dynamic_array<int> array(4);
    EXPECT_EQ(array.get_length(), 4);
}

TEST(test_dynamic_array, constructor_from_data)
{
    int array_one[] = {1, 2, 3, 4, 5};
    dynamic_array<int> array_two(array_one, 5);
    EXPECT_EQ(array_two.get_length(), 5);
    EXPECT_EQ(array_two.get_first(), 1);
    EXPECT_EQ(array_two.get_last(), 5);
}

TEST(test_dynamic_array, constructor_initializer_list)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    EXPECT_EQ(array.get_length(), 5);
    EXPECT_EQ(array.get_first(), 1);
    EXPECT_EQ(array.get_last(), 5);
}

TEST(test_dynamic_array, copy_constructor)
{
    dynamic_array<int> array_one = {1, 2, 3, 4, 5};
    dynamic_array<int> array_two (array_one);
    EXPECT_EQ(array_two.get_length(), 5);
    EXPECT_EQ(array_two.get_first(), 1);
    EXPECT_EQ(array_two.get_last(), 5);
}

TEST(test_dynamic_array_functions, method_get)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    EXPECT_EQ(array.get(0), 1);
    EXPECT_EQ(array.get(-1), 5);
}

TEST(test_dynamic_array_functions, method_get_first)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    EXPECT_EQ(array.get_first(), 1);
}

TEST(test_dynamic_array_functions, method_get_last)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    EXPECT_EQ(array.get_last(), 5);
}

TEST(test_dynamic_array_functions, method_get_length)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    EXPECT_EQ(array.get_length(), 5);
}

TEST(test_dynamic_array_functions, method_resize)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    array.resize(9);
    EXPECT_EQ(array.get_length(), 9);
    EXPECT_EQ(array.get_first(), 1);
    EXPECT_EQ(array.get(3), 4);
    EXPECT_EQ(array.get(4), 5);
}

TEST(test_dynamic_array_functions, method_append_element)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    array.append_element(9);
    EXPECT_EQ(array.get_last(), 9);
    EXPECT_EQ(array.get(4), 5);
}

TEST(test_dynamic_array_functions, method_prepend_element)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    array.prepend_element(7);
    EXPECT_EQ(array.get_first(), 7);
    EXPECT_EQ(array.get_last(), 5);
}

TEST(test_dynamic_array_functions, method_insert_element)
{
    dynamic_array<int> array = {1, 2, 3, 4, 5};
    int index = 2;
    array.insert_element(8, index);
    EXPECT_EQ(array.get(2), 8);
}

TEST(test_dynamic_array_functions, method_clear)
{
    dynamic_array<int> array = {1, 2, 3};
    array.clear();
    EXPECT_EQ(array.get_length(), 0);
}