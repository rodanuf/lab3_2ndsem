#include <gtest/gtest.h>
#include "../headers/dynamic_array.hpp"
#include "../headers/array_sequence.hpp"
#include "../headers/linked_list.hpp"
#include "../headers/list_sequence.hpp"
#include "../headers/stack.hpp"
#include "../ui_headers/io_functions.hpp"
#include "../types_headers/complex.hpp"
#include "../types_headers/student.hpp"
#include "../types_headers/professor.hpp"

#include "test_dynamic_array.cpp"
#include "test_array_sequence.cpp"
#include "test_linked_list.cpp"
#include "test_list_sequence.cpp"
#include "test_stack.cpp"
#include "test_complex.cpp"
#include "test_student.cpp"
#include "test_professor.cpp"
#include "test_io_functions.cpp"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(color) = 1;
    return RUN_ALL_TESTS();
}