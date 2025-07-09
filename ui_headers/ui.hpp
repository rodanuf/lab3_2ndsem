#pragma once
#include <limits>
#include <memory>
#include "../headers/sequence.hpp"
#include "../headers/array_sequence.hpp"
#include "../headers/list_sequence.hpp"
#include "../headers/stack.hpp"

template <typename T>
void print_sequence(sequence<T> *container);
template <typename T>
void print_stack(stack<T> *container);
void check_input(int &choice);
void output_types_menu(int &sequence_type);
template <typename T>
void set_sequence_type(int &sequence_type);
template <typename T>
void output_sequence_menu(sequence<T> *sequence);
template <typename T>
void output_stack_menu(stack<T> *stack);