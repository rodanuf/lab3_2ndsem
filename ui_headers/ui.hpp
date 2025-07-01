#pragma once
#include <limits>
#include <memory>
#include "../headers/sequence.hpp"
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"
#include "../headers/stack.hpp"

void check_input(int &choice);
void get_types_menu(int &sequence_type);
template <typename T>
void get_sequence_type(int &sequence_type);
template <typename T>
void sequence_menu(sequence<T> *sequence);