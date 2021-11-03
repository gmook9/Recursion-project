//
// Template Created by Ali A. Kooshesh on September  2020
// Created by Garret Mook on 03/01/21
//

//Start PROJECT NOTES
//*************
//Professor will use his OWN main.cpp in order to test the functions.
//Each test does NOT need to be commented out in the end.
//Project2.cpp and project2.hpp are pulled into a seperate directly and ran
//DO NOT include any helper functions inside of the main.cpp for this reason.
//Once again, can LEAVE function calls uncommented.
//*************
//End PROJECT NOTES

#include<iostream>
#include<vector>

#include "project2.hpp"

int main(int argc, char *argv[]) {
    if( argc != 2 ) {
        std::cout << "usage:" << argv[0] << " nameOfInputFile\n";
        exit(2);
    }
    //New Vector created to get away from allocating the size of the
    //results vector when we want it to be zero for a new function
    std::vector<int> results_leftRight;
    std::vector<int> results_leftRight_rec;
    std::vector<int> numbers, result;
    read_numbers(std::string(argv[1]), numbers);
    //  largest_left_recursive(numbers, result, numbers.length());
    for(int v: result)
        std::cout << v << std::endl;

    //Each 'BLOCK' holds function calls that are using for testing.

    //BEGIN BLOCK 1
    //*
    //The first block does not test any of the 8 functions.
    //Instead it is used to test the output of the original vector
    //Therefore verifying the function read_numbers works.
    //Also allows for us to see whats currently in the input
    std::cout << "Numbers in the vector: ";
    test_output_vector(numbers);
    //*
    //END BLOCK 1

    //BEGIN BLOCK 2
    //*
    //Used to test count_inversions_iterative
    std::cout << std::endl;
    std::cout << "Number of inversions is iteratively: " <<   count_inversions_iterative(numbers) << std::endl;
    std::cout << "Number of inversions is recursively: " <<  count_inversions_recursive(numbers, numbers.size()) << std::endl;
    //*
    //END BLOCK 1

    //BEGIN BLOCK 3
    //*
    //Used to test largest_left
    std::cout << "Largest Left Iterative: ";
    largest_left_iterative(numbers, result);
    std::cout << std::endl;
    std::cout << "Largest Left Recursive: ";
    largest_left_recursive(numbers, result, numbers.size());
    std::cout << std::endl;
    //*
    //END BLOCK 3

    //BEGIN BLOCK 4
    //*
    //Used to test increasing_sequences
    std::cout << "increasing_sequences_iterative: " << increasing_sequences_iterative(numbers);
    std::cout << std::endl;
    std::cout << "increasing_sequences_recursive: " << increasing_sequences_recursive(numbers, 0);
    std::cout <<  std::endl;
    //*
    //END BLOCK 3

    //BEGIN BLOCK 5
    //*
    //Used to test larger_left_right
    std::cout<< "larger_left_right_iterative: ";
    larger_left_right_iterative(numbers, results_leftRight);
    std::cout << std::endl;
    std::cout<< "larger_left_right_recursive: ";
    larger_left_right_recursive(numbers, results_leftRight_rec, numbers.size());
    test_output_vector(results_leftRight_rec);
    std::cout << std::endl;
    //*
    //END BLOCK 5

    return 0;
}

