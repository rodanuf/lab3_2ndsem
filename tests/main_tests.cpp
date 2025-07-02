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

#include "test_dynamic_array.inc"
#include "test_array_sequence.inc"
#include "test_linked_list.inc"
#include "test_list_sequence.inc"
#include "test_stack.inc"
#include "test_complex.inc"
#include "test_student.inc"
#include "test_professor.inc"
#include "test_io_functions.inc"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}