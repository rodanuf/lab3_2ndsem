#include <gtest/gtest.h>
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"

template <typename T>
class testable_list_sequence : public list_sequence<T>
{
public:
    testable_list_sequence(const std::initializer_list<T> &list) : list_sequence<T>(list) {}

    using list_sequence<T>::begin_impl;
    using list_sequence<T>::end_impl;
    using list_sequence<T>::cbegin_impl;
    using list_sequence<T>::cend_impl;
};

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
    auto old_as_it = *(as_it++);
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
    auto old_as_it = *(as_it--);
    EXPECT_EQ(*old_as_it, array[1]);
    EXPECT_EQ(*as_it, array[0]);
}

TEST(test_array_sequence_iterator_operators, operator_appropriation)
{
    array_sequence<int> seq_one = {1, 2, 3};
    array_sequence<int> seq_two = {1, 2, 3};
    auto it_one = seq_one.begin();
    auto it_two = seq_two.begin();
    ++it_one;
    ASSERT_NE(*it_one, *it_two);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_array_sequence_iterator_operators, operator_increment_on)
{
    array_sequence<int> arr = {1, 2, 3, 4, 5};
    auto it = arr.begin();
    ASSERT_NE(*it, 5);
    it = it + 4;
    EXPECT_EQ(*it, 5);
}

TEST(test_array_sequence_iterator_operators, operator_decrement_on)
{
    array_sequence<int> arr = {1, 2, 3, 4, 5};
    auto it = arr.begin();
    it = it + 3;
    EXPECT_EQ(*it, 4);
    it = it - 2;
    EXPECT_EQ(*it, 2);
}

TEST(test_array_sequence_iterator_operators, operator_dereferencing)
{
    array_sequence<int> seq = {42};
    auto it = seq.begin();
    EXPECT_EQ(*it, 42);
    *it = 100;
    EXPECT_EQ(*it, 100);
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

TEST(test_array_sequence_iterator_operators, operator_equality_with_another_struct_type)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    dynamic_array<int>::array_iterator it_three(&array[3]);
    array_sequence<int>::as_iterator as_it_one(it_one);
    array_sequence<int>::as_iterator as_it_two(it_two);
    array_sequence<int>::as_iterator as_it_three(it_three);
    testable_list_sequence<int> list = {1, 2, 3, 4, 5};
    auto ls_it_one = *(list.begin_impl());
    auto ls_it_two = *(list.begin_impl());
    auto ls_it_three = *(*(list.begin_impl()) + 3);

    EXPECT_TRUE(as_it_one == ls_it_one);
    EXPECT_FALSE(as_it_two == ls_it_three);
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

TEST(test_array_sequence_iterator_operators, operator_nonequality_with_another_struct_type)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::array_iterator it_one(&array[0]);
    dynamic_array<int>::array_iterator it_two(&array[0]);
    dynamic_array<int>::array_iterator it_three(&array[3]);
    array_sequence<int>::as_iterator as_it_one(it_one);
    array_sequence<int>::as_iterator as_it_two(it_two);
    array_sequence<int>::as_iterator as_it_three(it_three);
    testable_list_sequence<int> list = {1, 2, 3, 4, 5};
    auto ls_it_one = *(list.cbegin_impl());
    auto ls_it_two = *(list.cbegin_impl());
    auto ls_it_three = *(*(list.cbegin_impl()) + 3);

    EXPECT_TRUE(as_it_two != ls_it_three);
    EXPECT_FALSE(as_it_one != ls_it_two);
}

TEST(test_array_sequence_iterator_operators, method_begin)
{
    array_sequence<int> array = {10, 20, 30};
    auto it = array.begin();
    EXPECT_EQ(*it, 10);
}

TEST(test_array_sequence_iterator_operators, method_end)
{
    array_sequence<int> array = {10, 20, 30};
    auto it = array.end();
    EXPECT_EQ(*(it - 1), 30);
}

TEST(test_array_sequence_const_iterator, base_constructor_iterator)
{
    array_sequence<int> seq = {42};
    auto it = seq.cbegin();
    EXPECT_EQ(*it, 42);
}

TEST(test_array_sequence_const_iterator, copy_constructor_iterator)
{
    int value = 42;
    dynamic_array<int>::const_array_iterator it(&value);
    array_sequence<int>::const_as_iterator as_it_one(it);
    array_sequence<int>::const_as_iterator as_it_two(as_it_one);
    EXPECT_EQ(as_it_two, as_it_one);
}

TEST(test_array_sequence_const_iterator_operators, pref_operator_increment)
{
    array_sequence<int> seq_one = {1, 2, 3};
    array_sequence<int> seq_two = {1, 2, 3};
    auto it_one = seq_one.cbegin();
    auto it_two = seq_two.cbegin();
    ++it_two;
    ASSERT_NE(*it_one, *it_two);
    ++it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 2);
}

TEST(test_array_sequence_const_iterator_operators, post_operator_increment)
{
    array_sequence<int> seq = {1, 2, 3};
    auto it = seq.cbegin();
    it++;
    EXPECT_EQ(*it, 2);
}

TEST(test_array_sequence_const_iterator_operators, pref_operator_decrement)
{
    array_sequence<int> seq_one = {1, 2, 3};
    array_sequence<int> seq_two = {1, 2, 3};
    auto it_one = seq_one.cbegin();
    ++it_one;
    auto it_two = seq_two.cbegin();
    ASSERT_NE(*it_one, *it_two);
    --it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 1);
}

TEST(test_array_sequence_const_iterator_operators, post_operator_decrement)
{
    array_sequence<int> seq = {1, 2, 3};
    auto it = seq.cbegin();
    ++it;
    EXPECT_EQ(*it, 2);
    it--;
    EXPECT_EQ(*it, 1);
}

TEST(test_array_sequence_const_iterator_operators, operator_appropriation)
{
    array_sequence<int> seq_one = {1, 2, 3};
    array_sequence<int> seq_two = {1, 2, 3};
    auto it_one = seq_one.cbegin();
    auto it_two = seq_two.cbegin();
    ++it_one;
    ASSERT_NE(*it_one, *it_two);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_array_sequence_const_iterator_operators, operator_increment_on)
{
    array_sequence<int> arr = {1, 2, 3, 4, 5};
    auto it = arr.cbegin();
    ASSERT_NE(*it, 5);
    it = it + 4;
    EXPECT_EQ(*it, 5);
}

TEST(test_array_sequence_const_iterator_operators, operator_decrement_on)
{
    array_sequence<int> arr = {1, 2, 3, 4, 5};
    auto it = arr.cbegin();
    it = it + 4;
    ASSERT_NE(*it, 1);
    it = it - 3;
    EXPECT_EQ(*it, 2);
}

TEST(test_array_sequence_const_iterator_operators, operator_dereferencing)
{
    array_sequence<int> arr = {1, 2, 3};
    auto as_it = arr.cbegin();
    EXPECT_EQ(*as_it, 1);
}

TEST(test_array_sequence_const_iterator_operators, operator_equality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::const_array_iterator it_one(&array[0]);
    dynamic_array<int>::const_array_iterator it_two(&array[0]);
    dynamic_array<int>::const_array_iterator it_three(&array[3]);
    array_sequence<int>::const_as_iterator as_it_one(it_one);
    array_sequence<int>::const_as_iterator as_it_two(it_two);
    array_sequence<int>::const_as_iterator as_it_three(it_three);
    EXPECT_TRUE(as_it_one == as_it_two);
    EXPECT_FALSE(as_it_two == as_it_three);
}

TEST(test_array_sequence_const_iterator_operators, operator_nonequality)
{
    int array[] = {1, 2, 3, 4, 5};
    dynamic_array<int>::const_array_iterator it_one(&array[0]);
    dynamic_array<int>::const_array_iterator it_two(&array[0]);
    dynamic_array<int>::const_array_iterator it_three(&array[3]);
    array_sequence<int>::const_as_iterator as_it_one(it_one);
    array_sequence<int>::const_as_iterator as_it_two(it_two);
    array_sequence<int>::const_as_iterator as_it_three(it_three);
    EXPECT_TRUE(as_it_two != as_it_three);
    EXPECT_FALSE(as_it_one != as_it_two);
}

TEST(test_array_sequence_const_iterator_operators, method_begin)
{
    array_sequence<int> array = {10, 20, 30};
    auto it = array.cbegin();
    EXPECT_EQ(*it, 10);
}

TEST(test_array_sequence_const_iterator_operators, method_end)
{
    array_sequence<int> array = {10, 20, 30};
    auto it = array.cend();
    EXPECT_EQ(*(it - 1), 30);
}

TEST(test_array_sequence, basic_constructor)
{
    array_sequence<int> array;
    EXPECT_EQ(array.get_length(), 0);
}

TEST(test_array_sequence, constructor_by_size)
{
    array_sequence<int> array(4);
    EXPECT_EQ(array.get_length(), 4);
}

TEST(test_array_sequence, constructor_from_data)
{
    int items[] = {1, 2, 3, 4};
    array_sequence<int> array(items, 4);
    EXPECT_EQ(array.get_length(), 4);
    EXPECT_EQ(array.get_first(), 1);
    EXPECT_EQ(array.get_last(), 4);
}

TEST(test_array_sequence, constructor_initializer_list)
{
    array_sequence<int> array = {1, 2, 3, 4};
    EXPECT_EQ(array.get_length(), 4);
    EXPECT_EQ(array.get_first(), 1);
    EXPECT_EQ(array.get_last(), 4);
}

TEST(test_array_sequence, copy_constructor)
{
    array_sequence<int> array_one = {1, 2, 3, 4};
    array_sequence<int> array_two(array_one);
    EXPECT_EQ(array_two.get_length(), 4);
    EXPECT_EQ(array_two.get_first(), 1);
    EXPECT_EQ(array_two.get_last(), 4);
}

TEST(test_array_sequence_operators, operator_subscript)
{
    array_sequence<int> array = {10, 20, 30, 40};
    EXPECT_EQ(array[0], 10);
    EXPECT_EQ(array[1], 20);
    EXPECT_EQ(array[3], 40);
    array[2] = 100;
    EXPECT_EQ(array[2], 100);
    const array_sequence<int> const_array = {5, 10, 15};
    EXPECT_EQ(const_array[1], 10);
    EXPECT_THROW(array[-1], std::out_of_range);
    EXPECT_THROW(array[100], std::out_of_range);
}

TEST(test_array_sequence_functions, method_get)
{
    array_sequence<int> array = {1, 2, 3, 4};
    array_sequence<int> empty_array;
    EXPECT_THROW(empty_array.get(3), std::out_of_range);
    EXPECT_EQ(array.get(2), 3);
    EXPECT_EQ(array.get(3), 4);
    EXPECT_EQ(array.get(0), 1);
}

TEST(test_array_sequence_functions, method_get_first)
{
    array_sequence<int> array = {1, 2, 3, 4};
    array_sequence<int> empty_array;
    EXPECT_THROW(empty_array.get_first(), std::out_of_range);
    EXPECT_EQ(array.get_first(), 1);
}

TEST(test_array_sequence_functions, method_get_last)
{
    array_sequence<int> array = {1, 2, 3, 4};
    array_sequence<int> empty_array;
    EXPECT_THROW(empty_array.get_last(), std::out_of_range);
    EXPECT_EQ(array.get_last(), 4);
}

TEST(test_array_sequence_functions, method_get_length)
{
    array_sequence<int> array = {1, 2, 3, 4};
    EXPECT_EQ(array.get_length(), 4);
}

TEST(test_array_sequence_functions, method_get_subsequence)
{
    array_sequence<int> array = {1, 2, 3, 4, 5};
    EXPECT_THROW(array.get_subsequence(1, 6), std::out_of_range);
    EXPECT_THROW(array.get_subsequence(-1, 3), std::out_of_range);
    sequence<int> *subseq = array.get_subsequence(1, 3);
    ASSERT_NE(subseq, nullptr);
    EXPECT_EQ(subseq->get_length(), 3);
    EXPECT_EQ(subseq->get_first(), 2);
    EXPECT_EQ(subseq->get_last(), 4);
}

TEST(test_array_sequence_functions, method_append_element)
{
    array_sequence<int> array = {1, 2, 3, 4};
    array.append_element(12131415);
    EXPECT_EQ(array.get_last(), 12131415);
}

TEST(test_array_sequence_functions, method_prepend_element)
{
    array_sequence<int> array = {1, 2, 3, 4};
    array.prepend_element(-1);
    EXPECT_EQ(array.get_first(), -1);
    EXPECT_EQ(array.get(1), 1);
    EXPECT_EQ(array.get_last(), 4);
}

TEST(test_array_sequence_functions, method_insert_element)
{
    array_sequence<int> array = {1, 2, 3, 5};
    array.insert_element(4, 3);
    EXPECT_EQ(array.get_length(), 5);
    EXPECT_EQ(array.get(3), 4);
    EXPECT_EQ(array.get(4), 5);
    EXPECT_EQ(array.get(2), 3);
}

TEST(test_array_sequence_functions, method_remove_at)
{
    array_sequence<int> array = {1, 2, 3, 5};
    array.remove_at(3);
    EXPECT_EQ(array.get_last(), 3);
    EXPECT_EQ(array.get_length(), 3);
    array.remove_at(0);
    EXPECT_EQ(array.get_first(), 2);
    EXPECT_EQ(array.get_length(), 2);
    EXPECT_THROW(array.remove_at(-1), std::out_of_range);
    EXPECT_THROW(array.remove_at(5), std::out_of_range);
}

TEST(test_array_sequence_functions, method_concat)
{
    int ar_one[] = {1, 2, 3, 4};
    sequence<int> *array = new array_sequence<int>(ar_one, 4);
    int ar_two[] = {5, 6, 7, 8};
    sequence<int> *other = new array_sequence<int>(ar_two, 4);
    array = array->concat(*other);
    EXPECT_EQ(array->get_length(), 8);
    EXPECT_EQ(array->get(7), 8);
    EXPECT_EQ(array->get(5), 6);
    EXPECT_EQ(array->get(3), 4);
}

TEST(test_array_sequence_functions, method_immutable_append_element)
{
    array_sequence<int> array = {1, 2, 3, 4};
    sequence<int> *other = array.immutable_append_element(5);
    EXPECT_EQ(other->get_last(), 5);
    EXPECT_EQ(other->get(3), 4);
    EXPECT_EQ(other->get_length(), 5);
    EXPECT_EQ(array.get_last(), 4);
}

TEST(test_array_sequence_functions, method_immutable_prepend_element)
{
    array_sequence<int> array = {1, 2, 3, 4};
    sequence<int> *other = array.immutable_prepend_element(-1);
    EXPECT_EQ(other->get_first(), -1);
    EXPECT_EQ(other->get(3), 3);
    EXPECT_EQ(other->get_length(), 5);
    EXPECT_EQ(array.get_first(), 1);
}

TEST(test_array_sequence_functions, method_immutable_insert_element)
{
    array_sequence<int> array = {1, 2, 3, 4};
    sequence<int> *other = array.immutable_insert_element(5, 2);
    EXPECT_EQ(other->get(2), 5);
    EXPECT_EQ(other->get(3), 3);
    EXPECT_EQ(other->get_length(), 5);
    EXPECT_EQ(array.get(2), 3);
}

TEST(test_array_sequence_functions, method_immutable_remove_at)
{
    array_sequence<int> array = {1, 2, 3, 4, 5};
    sequence<int> *result = array.immutable_remove_at(2);
    EXPECT_EQ(result->get_length(), 4);
    EXPECT_EQ(result->get(0), 1);
    EXPECT_EQ(result->get(1), 2);
    EXPECT_EQ(result->get(2), 4);
    EXPECT_EQ(result->get(3), 5);
    sequence<int> *result_first = array.immutable_remove_at(0);
    EXPECT_EQ(result_first->get_length(), 4);
    EXPECT_EQ(result_first->get_first(), 2);
    sequence<int> *result_last = array.immutable_remove_at(4);
    EXPECT_EQ(result_last->get_length(), 4);
    EXPECT_EQ(result_last->get_last(), 4);
    EXPECT_EQ(array.get_length(), 5);
    EXPECT_EQ(array.get(2), 3);
    EXPECT_THROW(array.immutable_remove_at(-1), std::out_of_range);
    EXPECT_THROW(array.immutable_remove_at(6), std::out_of_range);
}

TEST(test_array_sequence_functions, method_immutable_concat)
{
    int ar_one[] = {1, 2, 3, 4};
    sequence<int> *array = new array_sequence<int>(ar_one, 4);
    int ar_two[] = {5, 6, 7, 8};
    sequence<int> *other = new array_sequence<int>(ar_two, 4);
    const sequence<int> *other_two = array->immutable_concat(*other);
    EXPECT_EQ(other_two->get(7), 8);
    EXPECT_EQ(other_two->get_length(), 8);
    EXPECT_EQ(array->get_last(), 4);
}

TEST(test_array_sequence_functions, method_clear)
{
    array_sequence<int> array = {1, 2, 3, 4};
    array.clear();
    EXPECT_EQ(array.get_length(), 0);
}