#include <gtest/gtest.h>
#include "../ui_headers/io_functions.hpp"

TEST(test_io_functions, student_input_operator_valid) 
{
    student s;
    std::istringstream iss("John Doe Group1 4.5");
    iss >> s;
    
    EXPECT_EQ(s.get_name(), "John");
    EXPECT_EQ(s.get_surname(), "Doe");
    EXPECT_EQ(s.get_group_number(), "Group1");
    EXPECT_FLOAT_EQ(s.get_grade(), 4.5);
    EXPECT_FALSE(iss.fail());
}

TEST(test_io_functions, student_input_operator_invalid_grade) 
{
    student s;
    std::istringstream iss("John Doe Group1 6.0");
    iss >> s;
    
    EXPECT_TRUE(iss.fail());
}

TEST(test_io_functions, student_output_operator) 
{
    student s("John", "Doe", "Group1", 4.5);
    std::ostringstream oss;
    oss << s;
    
    EXPECT_EQ(oss.str(), "John Doe Group1 4.5");
}

TEST(test_io_functions, professor_input_operator_valid) 
{
    professor p;
    std::istringstream iss("John Doe Physics 101");
    iss >> p;
    
    EXPECT_EQ(p.get_name(), "John");
    EXPECT_EQ(p.get_surname(), "Doe");
    EXPECT_EQ(p.get_name_departament(), "Physics");
    EXPECT_EQ(p.get_num_departament(), 101);
    EXPECT_FALSE(iss.fail());
}

TEST(test_io_functions, professor_output_operator) 
{
    professor p("John", "Doe", "Physics", 101);
    std::ostringstream oss;
    oss << p;
    
    EXPECT_EQ(oss.str(), "John Doe Physics 101");
}

TEST(test_io_functions, complex_input_operator_real_only) 
{
    complex c;
    std::istringstream iss("3.14");
    iss >> c;
    
    EXPECT_DOUBLE_EQ(c.get_real(), 3.14);
    EXPECT_DOUBLE_EQ(c.get_imag(), 0.0);
}

TEST(test_io_functions, complex_input_operator_imag_only) 
{
    complex c;
    std::istringstream iss("2.71i");
    iss >> c;
    
    EXPECT_DOUBLE_EQ(c.get_real(), 0.0);
    EXPECT_DOUBLE_EQ(c.get_imag(), 2.71);
    EXPECT_FALSE(iss.fail());
}

TEST(test_io_functions, complex_input_operator_full) 
{
    complex c;
    std::istringstream iss("1.5 + 2.5i");
    iss >> c;
    
    EXPECT_DOUBLE_EQ(c.get_real(), 1.5);
    EXPECT_DOUBLE_EQ(c.get_imag(), 2.5);
    EXPECT_FALSE(iss.fail());
}

TEST(test_io_functions, complex_input_operator_invalid_format) 
{
    complex c;
    std::istringstream iss("1.5 + 2.5");
    iss >> c;
    
    EXPECT_TRUE(iss.fail());
}

TEST(test_io_functions, complex_output_operator_real_only) 
{
    complex c(3.14, 0.0);
    std::ostringstream oss;
    oss << c;
    
    EXPECT_EQ(oss.str(), "3.14");
}

TEST(test_io_functions, complex_output_operator_imag_only)
{
    complex c(0.0, 2.71);
    std::ostringstream oss;
    oss << c;
    
    EXPECT_EQ(oss.str(), "0 + 2.71i");
}

TEST(test_io_functions, complex_output_operator_negative_imag) 
{
    complex c(1.0, -1.0);
    std::ostringstream oss;
    oss << c;
    
    EXPECT_EQ(oss.str(), "1-i");
}

TEST(test_io_functions, complex_output_operator_full) 
{
    complex c(1.5, 2.5);
    std::ostringstream oss;
    oss << c;
    
    EXPECT_EQ(oss.str(), "1.5 + 2.5i");
}
