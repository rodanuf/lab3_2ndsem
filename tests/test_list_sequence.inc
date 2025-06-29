#include <gtest/gtest.h>
#include "../headers/list_sequence.hpp"

TEST(test_list_sequence_iterator, base_constructor_iterator)
{
    list_sequence<int> seq = {42};
    auto it = seq.begin();
    EXPECT_EQ(*it, 42);
}

TEST(test_list_sequence_iterator, copy_constructor_iterator)
{
    list_sequence<int> seq = {42};
    auto it_one = seq.begin();
    auto it_two = it_one;
    EXPECT_EQ(it_two, it_one);
}

TEST(test_list_sequence_iterator_operators, pref_operator_increment)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it_one = seq.begin();
    auto it_two = seq.begin();
    ++it_two;
    ASSERT_NE(*it_one, *it_two); 
    ++it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 2);
}

TEST(test_list_sequence_iterator_operators, post_operator_increment)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it = seq.begin();
    auto old_it = it++;
    EXPECT_EQ(*old_it, 1);
    EXPECT_EQ(*it, 2);
}

TEST(test_list_sequence_iterator_operators, pref_operator_decrement)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it_one = seq.begin();
    ++it_one;
    auto it_two = seq.begin();
    ASSERT_NE(*it_one, *it_two);
    --it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 1);
}

TEST(test_list_sequence_iterator_operators, post_operator_decrement)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it = seq.begin();
    ++it;
    EXPECT_EQ(*it, 2);
    auto old_it = it--;
    EXPECT_EQ(*old_it, 2);
    EXPECT_EQ(*it, 1);    
}

TEST(test_list_sequence_iterator_operators, operator_appropriation)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it_one = seq.begin();
    auto it_two = seq.begin();
    ++it_one;
    ASSERT_NE(*it_one, *it_two);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_list_sequence_iterator_operators, operator_increment_on)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it = seq.begin();
    ASSERT_NE(*it, 5);
    it = it + 4;
    EXPECT_EQ(*it, 5); 
}

TEST(test_list_sequence_iterator_operators, operator_decrement_on)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it = seq.begin();
    it = it + 3;
    ASSERT_NE(*it, 1);
    it = it - 3;
    EXPECT_EQ(*it, 1);
}

TEST(test_list_sequence_iterator_operators, operator_dereferencing)
{
    list_sequence<int> seq = {42};
    auto it = seq.begin();
    EXPECT_EQ(*it, 42);
    *it = 100;
    EXPECT_EQ(*it, 100);
}

TEST(test_list_sequence_iterator_operators, operator_accessing_an_element)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it = seq.begin();
    EXPECT_EQ(it[0], 1);
    EXPECT_EQ(it[4], 5);
    it[1] = 50;
    EXPECT_EQ(it[1], 50);
}

TEST(test_list_sequence_iterator_operators, operator_equality)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it_one = seq.begin();
    auto it_two = seq.begin();
    auto it_three = seq.begin();
    it_three = it_three + 3;
    EXPECT_TRUE(it_one == it_two);
    EXPECT_FALSE(it_two == it_three);    
}

TEST(test_list_sequence_iterator_operators, operator_nonequality)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it_one = seq.begin();
    auto it_two = seq.begin();
    auto it_three = seq.begin();
    it_three = it_three + 3;
    EXPECT_TRUE(it_two != it_three);
    EXPECT_FALSE(it_one != it_two);
}

TEST(test_list_sequence_iterator_operators, method_begin)
{
    list_sequence<int> seq = {10, 20, 30};
    auto it = seq.begin();
    EXPECT_EQ(*it, 10);
}

TEST(test_list_sequence_iterator_operators, method_end)
{
    list_sequence<int> seq = {10, 20, 30};
    auto it = seq.end();
    EXPECT_EQ(*(it - 1), 30);
}

TEST(test_list_sequence_const_iterator, base_constructor_iterator)
{
    list_sequence<int> seq = {42};
    auto it = seq.cbegin();
    EXPECT_EQ(*it, 42);
}

TEST(test_list_sequence_const_iterator, copy_constructor_iterator)
{
    list_sequence<int> seq = {42};
    auto it_one = seq.cbegin();
    auto it_two = it_one;
    EXPECT_EQ(it_two, it_one);
}

TEST(test_list_sequence_const_iterator_operators, pref_operator_increment)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it_one = seq.cbegin();
    auto it_two = seq.cbegin();
    ++it_two;
    ASSERT_NE(*it_one, *it_two); 
    ++it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 2);
}

TEST(test_list_sequence_const_iterator_operators, post_operator_increment)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it = seq.cbegin();
    auto old_it = it++;
    EXPECT_EQ(*old_it, 1);
    EXPECT_EQ(*it, 2);
}

TEST(test_list_sequence_const_iterator_operators, pref_operator_decrement)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it_one = seq.cbegin();
    ++it_one;
    auto it_two = seq.cbegin();
    ASSERT_NE(*it_one, *it_two);
    --it_one;
    EXPECT_EQ(*it_one, *it_two);
    EXPECT_EQ(*it_one, 1);
}

TEST(test_list_sequence_const_iterator_operators, post_operator_decrement)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it = seq.cbegin();
    ++it;
    EXPECT_EQ(*it, 2);
    auto old_it = it--;
    EXPECT_EQ(*old_it, 2);
    EXPECT_EQ(*it, 1);    
}

TEST(test_list_sequence_const_iterator_operators, operator_appropriation)
{
    list_sequence<int> seq = {1, 2, 3};
    auto it_one = seq.cbegin();
    auto it_two = seq.cbegin();
    ++it_one;
    ASSERT_NE(*it_one, *it_two);
    it_one = it_two;
    EXPECT_EQ(*it_one, *it_two);
}

TEST(test_list_sequence_const_iterator_operators, operator_increment_on)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it = seq.cbegin();
    ASSERT_NE(*it, 5);
    it = it + 4;
    EXPECT_EQ(*it, 5); 
}

TEST(test_list_sequence_const_iterator_operators, operator_decrement_on)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it = seq.cbegin();
    it = it + 3;
    ASSERT_NE(*it, 1);
    it = it - 3;
    EXPECT_EQ(*it, 1);
}

TEST(test_list_sequence_const_iterator_operators, operator_dereferencing)
{
    list_sequence<int> seq = {42};
    auto it = seq.cbegin();
    EXPECT_EQ(*it, 42);
}

TEST(test_list_sequence_const_iterator_operators, operator_accessing_an_element)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it = seq.cbegin();
    EXPECT_EQ(it[0], 1);
    EXPECT_EQ(it[4], 5);
}

TEST(test_list_sequence_const_iterator_operators, operator_equality)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it_one = seq.cbegin();
    auto it_two = seq.cbegin();
    auto it_three = seq.cbegin();
    it_three = it_three + 3;
    EXPECT_TRUE(it_one == it_two);
    EXPECT_FALSE(it_two == it_three);    
}

TEST(test_list_sequence_const_iterator_operators, operator_nonequality)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    auto it_one = seq.cbegin();
    auto it_two = seq.cbegin();
    auto it_three = seq.cbegin();
    it_three = it_three + 3;
    EXPECT_TRUE(it_two != it_three);
    EXPECT_FALSE(it_one != it_two);
}

TEST(test_list_sequence_const_iterator_operators, method_begin)
{
    list_sequence<int> seq = {10, 20, 30};
    auto it = seq.cbegin();
    EXPECT_EQ(*it, 10);
}

TEST(test_list_sequence_const_iterator_operators, method_end)
{
    list_sequence<int> seq = {10, 20, 30};
    auto it = seq.cend();
    EXPECT_EQ(*(it - 1), 30);
}

TEST(test_list_sequence, basic_constructor)
{
    list_sequence<int> seq;
    EXPECT_EQ(seq.get_length(), 0);
}

TEST(test_list_sequence, constructor_by_size)
{
    list_sequence<int> seq(4);
    EXPECT_EQ(seq.get_length(), 4);
}

TEST(test_list_sequence, constructor_from_data)
{
    int items[] = {1, 2, 3, 4}; 
    list_sequence<int> seq(items, 4);
    EXPECT_EQ(seq.get_length(), 4);
    EXPECT_EQ(seq.get_first(), 1);
    EXPECT_EQ(seq.get_last(), 4);
}

TEST(test_list_sequence, constructor_initializer_list)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    EXPECT_EQ(seq.get_length(), 4);
    EXPECT_EQ(seq.get_first(), 1);
    EXPECT_EQ(seq.get_last(), 4);
}

TEST(test_list_sequence, copy_constructor)
{
    list_sequence<int> seq_one = {1, 2, 3, 4};
    list_sequence<int> seq_two(seq_one);
    EXPECT_EQ(seq_two.get_length(), 4);
    EXPECT_EQ(seq_two.get_first(), 1);
    EXPECT_EQ(seq_two.get_last(), 4);
}

TEST(test_list_sequence_functions, method_get)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    list_sequence<int> empty_seq;
    EXPECT_THROW(empty_seq.get(3), std::out_of_range);
    EXPECT_EQ(seq.get(2), 3);
    EXPECT_EQ(seq.get(3), 4);
    EXPECT_EQ(seq.get(0), 1);
}

TEST(test_list_sequence_functions, method_get_first)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    list_sequence<int> empty_seq;
    EXPECT_THROW(empty_seq.get_first(), std::out_of_range);
    EXPECT_EQ(seq.get_first(), 1);
}

TEST(test_list_sequence_functions, method_get_last)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    list_sequence<int> empty_seq;
    EXPECT_THROW(empty_seq.get_last(), std::out_of_range);
    EXPECT_EQ(seq.get_last(), 4);
}

TEST(test_list_sequence_functions, method_get_length)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    EXPECT_EQ(seq.get_length(), 4);
}

TEST(test_list_sequence_functions, method_get_subsequence)
{
    list_sequence<int> seq = {1, 2, 3, 4, 5};
    EXPECT_THROW(seq.get_subsequence(1, 6), std::out_of_range);
    EXPECT_THROW(seq.get_subsequence(-1, 3), std::out_of_range);
    sequence<int>* subseq = seq.get_subsequence(1, 3);
    ASSERT_NE(subseq, nullptr);
    EXPECT_EQ(subseq->get_length(), 3);
    EXPECT_EQ(subseq->get_first(), 2);
    EXPECT_EQ(subseq->get_last(), 4);
}

TEST(test_list_sequence_functions, method_append_element)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    seq.append_element(12131415);
    EXPECT_EQ(seq.get_last(), 12131415);
}

TEST(test_list_sequence_functions, method_prepend_element)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    seq.prepend_element(-1);
    EXPECT_EQ(seq.get_first(), -1);
    EXPECT_EQ(seq.get(1), 1);
    EXPECT_EQ(seq.get_last(), 4);
}

TEST(test_list_sequence_functions, method_insert_element)
{
    list_sequence<int> seq = {1, 2, 3, 5};
    seq.insert_element(4, 3);
    EXPECT_EQ(seq.get_length(), 5);
    EXPECT_EQ(seq.get(3), 4);
    EXPECT_EQ(seq.get(4), 5);
    EXPECT_EQ(seq.get(2), 3);
}

TEST(test_list_sequence_functions, method_concat)
{
    int ar_one[] = {1, 2, 3, 4}; 
    sequence<int> *seq = new list_sequence<int>(ar_one, 4);
    int ar_two[] = {5, 6, 7, 8};
    sequence<int> *other = new list_sequence<int>(ar_two, 4);
    seq = seq->concat(*other);
    EXPECT_EQ(seq->get_length(), 8);
    EXPECT_EQ(seq->get(7), 8);
    EXPECT_EQ(seq->get(5), 6);
    EXPECT_EQ(seq->get(3), 4);
}

TEST(test_list_sequence_functions, method_immutable_append_element)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    sequence<int> *other = seq.immutable_append_element(5);
    EXPECT_EQ(other->get_last(), 5);
    EXPECT_EQ(other->get(3), 4);
    EXPECT_EQ(other->get_length(), 5);
    EXPECT_EQ(seq.get_last(), 4);
}

TEST(test_list_sequence_functions, method_immutable_prepend_element)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    sequence<int> *other = seq.immutable_prepend_element(-1);
    EXPECT_EQ(other->get_first(), -1);
    EXPECT_EQ(other->get(3), 3);
    EXPECT_EQ(other->get_length(), 5);
    EXPECT_EQ(seq.get_first(), 1);
}

TEST(test_list_sequence_functions, method_immutable_insert_element)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    sequence<int> *other = seq.immutable_insert_element(5, 2);
    EXPECT_EQ(other->get(2), 5);
    EXPECT_EQ(other->get(3), 3);
    EXPECT_EQ(other->get_length(), 5);
    EXPECT_EQ(seq.get(2), 3);
}

TEST(test_list_sequence_functions, method_immutable_concat)
{
    int ar_one[] = {1, 2, 3, 4};
    sequence<int> *seq = new list_sequence<int>(ar_one, 4);
    int ar_two[] = {5, 6, 7, 8};
    sequence<int> *other = new list_sequence<int>(ar_two, 4);
    const sequence<int> *other_two = seq->immutable_concat(*other);
    EXPECT_EQ(other_two->get(7), 8);
    EXPECT_EQ(other_two->get_length(), 8);
    EXPECT_EQ(seq->get_last(), 4);
}

TEST(test_list_sequence_functions, method_clear)
{
    list_sequence<int> seq = {1, 2, 3, 4};
    seq.clear();
    EXPECT_EQ(seq.get_length(), 0);
}