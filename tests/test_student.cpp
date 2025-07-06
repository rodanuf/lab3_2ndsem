#include <gtest/gtest.h>
#include "../types_headers/student.hpp"

TEST(test_student_constructors, default_constructor)
{
    student s;
    EXPECT_EQ(s.get_name(), "");
    EXPECT_EQ(s.get_surname(), "");
    EXPECT_EQ(s.get_group_number(), "");
    EXPECT_DOUBLE_EQ(s.get_grade(), 0.0);
}

TEST(test_student_constructors, constructor_with_name_and_grade)
{
    student s("Ivan", 4.5);
    EXPECT_EQ(s.get_name(), "Ivan");
    EXPECT_EQ(s.get_surname(), "");
    EXPECT_EQ(s.get_group_number(), "");
    EXPECT_DOUBLE_EQ(s.get_grade(), 4.5);
}

TEST(test_student_constructors, full_constructor)
{
    student s("Fedor", "Dostoevsky", "Б24-504", 4.5);
    EXPECT_EQ(s.get_name(), "Fedor");
    EXPECT_EQ(s.get_surname(), "Dostoevsky");
    EXPECT_EQ(s.get_group_number(), "Б24-504");
    EXPECT_DOUBLE_EQ(s.get_grade(), 4.5);
}

TEST(test_student_operators, operator_equality)
{
    student s1("Roman", "Romanov", "Б24-504", 4.5);
    student s2("Roman", "Romanov", "Б24-504", 4.5);
    student s3("Roman", "Romanov", "С24-504", 4.5);

    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

TEST(test_student_operators, operator_inequality)
{
    student s1("Roman", "Romanov", "Б24-504", 4.5);
    student s2("Roman", "Romanov", "Б24-504", 4.5);
    student s3("Roman", "Romanov", "С24-504", 4.5);

    EXPECT_FALSE(s1 != s2);
    EXPECT_TRUE(s1 != s3);
}

TEST(test_student_operators, operator_less_than)
{
    student s1("Alex", 3.5);
    student s2("Jane", 4.5);

    EXPECT_TRUE(s1 < s2);
    EXPECT_FALSE(s2 < s1);
}

TEST(test_student_operators, operator_greater_than)
{
    student s1("Alex", 4.5);
    student s2("Jane", 3.5);

    EXPECT_TRUE(s1 > s2);
    EXPECT_FALSE(s2 > s1);
}

TEST(test_student_methods, getters_and_setters)
{
    student s;

    s.set_name("Alex");
    s.set_surname("Doe");
    s.set_group_number("CS101");
    s.set_grade(4.5);

    EXPECT_EQ(s.get_name(), "Alex");
    EXPECT_EQ(s.get_surname(), "Doe");
    EXPECT_EQ(s.get_group_number(), "CS101");
    EXPECT_DOUBLE_EQ(s.get_grade(), 4.5);
}

TEST(test_student_methods, set_name)
{
    student s;
    s.set_name("Alice");
    EXPECT_EQ(s.get_name(), "Alice");
}

TEST(test_student_methods, set_surname)
{
    student s;
    s.set_surname("Demidovich");
    EXPECT_EQ(s.get_surname(), "Demidovich");
}

TEST(test_student_methods, set_group_number)
{
    student s;
    s.set_group_number("Б24-202");
    EXPECT_EQ(s.get_group_number(), "Б24-202");
}

TEST(test_student_methods, set_grade)
{
    student s;
    s.set_grade(3.7);
    EXPECT_DOUBLE_EQ(s.get_grade(), 3.7);
}