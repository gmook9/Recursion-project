//
// Created by gmook on 3/3/2021.
//
#include <vector>
#include <string>

//These are GLOBAL functions. Therefore we are using NO class.
int count_inversions_iterative(const std::vector<int> &numbers); //Done && Working
int count_inversions_recursive(const std::vector<int> &numbers, int n);

void largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result);
void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);

void larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result);
void larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);

int increasing_sequences_iterative(std::vector<int> &numbers);
int increasing_sequences_recursive(std::vector<int> &numbers, int startIdx);

void read_numbers(std::string fileName, std::vector<int> &v);

//Created to test vector outputs
void test_output_vector(std::vector<int> &v);

//helper functions
int helper_seq_rec(std::vector<int> &numbers, int startIdx);
int largest_left_recursive_helper(const std::vector<int> &numbers, int base, int base_plus_one);
int larger_left_right_iterative_helper_b(const std::vector<int> &numbers, int base, int base_plus_one);
int larger_left_right_recursive_helper_looking_forward(const std::vector<int> &numbers, int base, int base_plus_one);
int check_for_biggest_side(int biggest_in_the_left, int biggest_in_the_right);
int check_for_biggest_side_iter(int biggest_element_to_the_left, int biggest_element_to_the_right);


