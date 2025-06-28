#include <gtest/gtest.h>
#include "../headers/dynamic_array.hpp"
#include "../headers/array_sequence.hpp"
#include "../headers/linked_list.hpp"

#include "test_dynamic_array.inc"
#include "test_array_sequence.inc"
#include "test_linked_list.inc"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}