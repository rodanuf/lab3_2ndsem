#include <gtest/gtest.h>
#include "../types_headers/professor.hpp"

TEST(test_professor_constructors, default_constructor) 
{
    professor p;
    EXPECT_EQ(p.get_name(), "");
    EXPECT_EQ(p.get_surname(), "");
    EXPECT_EQ(p.get_name_departament(), "");
    EXPECT_EQ(p.get_num_departament(), 0);
}

TEST(test_professor_constructors, constructor_with_name_surname_num) 
{
    professor p("Ivan", "Petrov", 42);
    EXPECT_EQ(p.get_name(), "Ivan");
    EXPECT_EQ(p.get_surname(), "Petrov");
    EXPECT_EQ(p.get_name_departament(), "");
    EXPECT_EQ(p.get_num_departament(), 42);
}

TEST(test_professor_constructors, full_constructor) 
{
    professor p("Fedor", "Dostoevsky", "Literature", 24);
    EXPECT_EQ(p.get_name(), "Fedor");
    EXPECT_EQ(p.get_surname(), "Dostoevsky");
    EXPECT_EQ(p.get_name_departament(), "Literature");
    EXPECT_EQ(p.get_num_departament(), 24);
}

TEST(test_professor_operators, operator_equality) 
{
    professor p1("Roman", "Romanov", "Mathematics", 504);
    professor p2("Roman", "Romanov", "Mathematics", 504);
    professor p3("Roman", "Romanov", "Physics", 504);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(test_professor_operators, operator_inequality) 
{
    professor p1("Roman", "Romanov", "Mathematics", 504);
    professor p2("Roman", "Romanov", "Mathematics", 504);
    professor p3("Roman", "Romanov", "Physics", 504);
    
    EXPECT_FALSE(p1 != p2);
    EXPECT_TRUE(p1 != p3);
}

TEST(test_professor_operators, operator_less_than) 
{
    professor p1("Alex", "Ivanov", 35);
    professor p2("Jane", "Smith", 45);
    
    EXPECT_TRUE(p1 < p2);
    EXPECT_FALSE(p2 < p1);
}

TEST(test_professor_operators, operator_greater_than) 
{
    professor p1("Alex", "Ivanov", 45);
    professor p2("Jane", "Smith", 35);
    
    EXPECT_TRUE(p1 > p2);
    EXPECT_FALSE(p2 > p1);
}

TEST(test_professor_methods, getters_and_setters) 
{
    professor p;
    
    p.set_name("Vladimir");
    p.set_surname("Roslovtsev");
    p.set_name_departament("Computer Science");
    p.set_num_departament(101);
    
    EXPECT_EQ(p.get_name(), "Vladimir");
    EXPECT_EQ(p.get_surname(), "Roslovtsev");
    EXPECT_EQ(p.get_name_departament(), "Computer Science");
    EXPECT_EQ(p.get_num_departament(), 101);
}

TEST(test_professor_methods, set_name) 
{
    professor p;
    p.set_name("Alice");
    EXPECT_EQ(p.get_name(), "Alice");
}

TEST(test_professor_methods, set_surname) 
{
    professor p;
    p.set_surname("Demidovich");
    EXPECT_EQ(p.get_surname(), "Demidovich");
}

TEST(test_professor_methods, set_name_departament) 
{
    professor p;
    p.set_name_departament("Applied Mathematics");
    EXPECT_EQ(p.get_name_departament(), "Applied Mathematics");
}

TEST(test_professor_methods, set_num_departament) 
{
    professor p;
    p.set_num_departament(202);
    EXPECT_EQ(p.get_num_departament(), 202);
}