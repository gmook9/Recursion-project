//
// Created and commented by Garret Mook on 3/3/2021.
//

#include "project2.hpp"
#include <vector>
#include <iostream>
#include <fstream>

//****************
//DONE
int count_inversions_iterative(const std::vector<int> &numbers) {
    //First, set the count equal to 0
    int count_inversions = 0;
    //Next, run one loop
    //One loop keeps track of elements
    //While the loop keep track of the elements
    //We use numbers.at(i+1) to get the element that is next
    for(int i = 0; i < numbers.size()-1; i++) {
        //If a number is found to be greater than the one that comes after it, add a count to the inversions
        if(numbers.at(i) > numbers.at(i+1)) {
            count_inversions++;
        }
    }
    //Return the number of inversions counted in total
    return count_inversions;
}
//****************

//****************
//DONE
int count_inversions_recursive(const std::vector<int> &numbers, int n) {
    //First check and make sure the length
    //of the vector is not zero
    //if the vector only contains none or 1
    //element then their can be no inversions so return 0
    if( n == 0 || n == 1) {
        return 0;
    }
    //Vector with 3 values stores those values in
    //*** v[0] , v[1], and v[2] ***
    //Therefore, we need to reach the previous element using
    // n - 2 and the element in-front of that is n -1
    if(numbers.at(n-2) > numbers.at(n-1)) {
        //If we find a element bigger than the one that will come next
        //then we return the same function recursively
        //However, we add 1 to the return value to be carried over which
        //will count the inversions
        //as well as we minus 1 from the n value in order to iterate
        //backwards through the vector
        return count_inversions_recursive(numbers, n - 1) + 1;
    }
    //If we DO NOT find a element bigger than the one that will come next
    //then we return the same function recursively but this time we DO NOT
    //add a one to be returned that way the count doesnt go up
    return count_inversions_recursive(numbers, n - 1);
}
//****************

//****************
//DONE
void largest_left_iterative_helper(const std::vector<int> &numbers, int n) {
//Nothing is going to be larger behind the first element
//Therefore we know we can console out 0 to start
//As well as this allows us to being our foor loop
//on the second element
    std::cout << "0 ";
    for (int i = 1; i < numbers.size(); i++) {
        int k;
        //Loop through a vector to see if there are any
        //values greater than i to the left
        for (k = i - 1; k >= 0; k--) {
            //When we find a number at i bigger than k
            //we then output that number
            if (numbers.at(i) < numbers.at(k)) {
                std::cout << numbers.at(k) << " ";
                break;
            }
        }
        //We dont set k == 0 because we know that k[0] is still a element
        //in the vector, therefore, we search for if k gets to -1 from k--
        //If k does equal -1 we know that a larger element was NOT found
        //inside of the FOR loop and therefore we output 0 to represent
        //that there is no greater value
        if (k == -1)
            std::cout << "0 ";
    }
}
//****************

//****************
//DONE
void largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result) {
    int n = numbers.size();
    //Here we call the helper function which ends up doing all the work.
    largest_left_iterative_helper(numbers, n);
}
//****************


//****************
//DONE
int largest_left_recursive_helper(const std::vector<int> &numbers, int base, int base_plus_one) {
    //If we DO not find it and go past the start of the vector
    //Return 0, meaning nothing bigger was ever found
    if (base == -1)
        return 0;
    //If we have NOT gone past the start of the vector then compare the element previous element to see if it is
    //greater, this is where incrementing base using base - 1 plays a big role
    if (base_plus_one < numbers.at(base))
        return numbers.at(base);
    //Return the function recursively while incrementing the base
    return largest_left_recursive_helper(numbers, base-1, base_plus_one);
}
//****************

//****************
//DONE
void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n) {
    //Set our starting position equal to zero
    int starting = numbers.size()-n;
    //Set our base equal to the starting value
    int base = starting;
    //Base_plus_one is initialized to the element at the start
    int num_at_base = numbers.at(base);
    int base_plus_one = num_at_base;
    //This IF statement only runs for the last element
    if(base == numbers.size()-1) {
        int largest_element_left_of_end_of_vector_setter = largest_left_recursive_helper(numbers, base, base_plus_one);
        int largest_element_left_of_end_of_vector = largest_element_left_of_end_of_vector_setter;
        result.push_back(largest_element_left_of_end_of_vector);
        test_output_vector(result);
        return;
    }
    //For every other element that the last element search for a larger element by looking
    //backwards from the current element. To do this a helper function is called which
    //searches for the biggest known element on the left side
    int largest_left_setter = largest_left_recursive_helper(numbers, base, base_plus_one);
    int largest_left = largest_left_setter;
    result.push_back(largest_left);
    largest_left_recursive(numbers, result, n-1);
}
//****************

//****************
//DONE
int larger_left_right_iterative_helper(const std::vector<int> &numbers, int base, int base_plus_one) {
    //larger_left_right_iterative_helper goes FORWARDS for the biggest element
    //Easy helper function created to look for the biggest element
    //in a vector, but forwards
    for(int i = base; i < numbers.size()-1; i++) {
        if(base_plus_one < numbers.at(i))
            return numbers.at(i);
    }
    //No larger elements found = return 0
    return 0;
}
//****************

//****************
//DONE
int larger_left_right_iterative_helper_b(const std::vector<int> &numbers, int base, int base_plus_one) {
    //larger_left_right_iterative_helper_b goes BACKWARDS for the biggest element
    //Easy helper function created to look for the biggest element
    //in a vector, but backwards
    for(int i = base; i > -1; i--) {
        if(base_plus_one < numbers.at(i))
            return numbers.at(i);
    }
    //No larger elements found = return 0
    return 0;
}
//****************

//****************
//**DONE
int check_for_biggest_side_iter(int biggest_element_to_the_left, int biggest_element_to_the_right) {
    //Using conditional statements (if and else if) we can determine the outputs into our result vector from the helper
    //functions. We do not need a ELSE statement because all our conditions should be met
    //When checking whether the left or right largest is bigger we are met with 4 cases
    //**** 4 Cases for Largest Left vs Largest Right ****
    //Case 1: The element found to be the largest on the left is bigger
    //than the one found on the right. Therefore, return the left
    if(biggest_element_to_the_left > biggest_element_to_the_right)
        return biggest_element_to_the_left;
        //Case 2: The element found to be the largest on the right is bigger
        //than the one found on the left. Therefore, return the right
    else if(biggest_element_to_the_right > biggest_element_to_the_left)
        return biggest_element_to_the_right;
        //Case 3: Both of the left and right helper functions fail to find
        //a larger element so they both return 0
    else if(biggest_element_to_the_left == 0 && biggest_element_to_the_right == 0)
        return 0;
        //Case 4: If both the largest on the left and right are found to be equal
        //then we can pick either the left or the right it does NOT make a difference
        //since they are equivalent
    else if(biggest_element_to_the_right == biggest_element_to_the_left)
        return biggest_element_to_the_right;
}
//****************

//****************
//DONE
void larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result) {
    //In the loop we are either at the first element, the last
    //element, or somewhere in-between. For this reason
    //we create 3 possible routes using a IF statement
    //Also,we create a element for the first and las in the case our search domain is ever changed we can use a element
    //to store that change throughout
    int zeroSetter = 0;
    int firstElement = 0;
    int finalElement = numbers.size() - 1;
    for(int base = 0; base < numbers.size(); base++) {
        //If we are at the starting element
        //The only thing we can do is compare it to elements that
        //exist in-front of it
        //NOTE: We always start at the first element because we set int base = 0 in the FOR loop
        //Therefore, the first time the FOR loop runs we know that this IF statement will always run
        if(base == firstElement) {
            //We can only look at elements to the right for a bigger element
            //So we call our helper function to find a element bigger to the right
            //If one exists
            int set_bigger_right_element = larger_left_right_iterative_helper(numbers, base, numbers.at(base));
            int bigger_right_element = set_bigger_right_element;
            //Whether we find a bigger element or we dont and get a return 0 we will either
            //pushback that 0 or the bigger element found
            result.push_back(bigger_right_element);
            //This completes what needs to be done for the first element in the vector
            //Next, we move on to look at the other elements
        }
            //If we are at the last element
            //The only thing we can do is compare it to elements that
            //exist before it
            //NOTE: We have already made a case to check for the first element of the vector
            //This case will only be triggered when base gets to the last element in the vector
            //Base is incremented inside the FOR loop which means it will always start at 0
            //because that what we declared but also always end at the last element because those are
            //the first two conditions in our FOR loop. The FOR loop gives the start and end contions
            //*** EXAMPLE: int base = 0; base < numbers.size(); ***
        else if(base == finalElement) {
            //We are at the end of the list so the only thing we can do is look backwards
            //Therefore, we simply implement out function that calls for us to look backwards
            //for the biggest element inside of the vector
            int set_bigger_left_element = larger_left_right_iterative_helper_b(numbers, base, numbers.at(base));
            int biggest_left_element = set_bigger_left_element;
            //Whether we find a bigger element or we dont and get a return 0 we will either
            //pushback that 0 or the bigger element found
            result.push_back(biggest_left_element);
        }
        //This ELSE case runs when we are NOT at the first or last element of the vector
        if(base != firstElement && base != finalElement) {

            //Creating a integer to store the biggest element found on the left of the current until the start of the vector
            int biggest_element_to_the_left_setter = larger_left_right_iterative_helper_b(numbers, base, numbers.at(base));
            int biggest_element_to_the_left = biggest_element_to_the_left_setter;
            //Creating a integer to store the biggest element found on the right of the current until the end of the vector
            int biggest_element_to_the_right_setter = larger_left_right_iterative_helper(numbers, base, numbers.at(base));
            int biggest_element_to_the_right = biggest_element_to_the_right_setter;
            result.push_back(check_for_biggest_side_iter(biggest_element_to_the_left, biggest_element_to_the_right));
        }
    }
    //At the end we simply run a function that prints out our result vector
    test_output_vector(result);
}
//****************

//****************
//DONE
int larger_left_right_recursive_helper_looking_forward(const std::vector<int> &numbers, int base, int base_plus_one) {
    //This HELPER function looks forward in the vector trying to find the largest element
    int end_of_vector = numbers.size()-1;
    int num_at_base = numbers.at(base);
    //IF we are at the end of the vector, than no element can be bigger
    //Therefore, we return 0 to say NO element is found bigger
    if (base == end_of_vector)
        return 0;
    //If a LARGER element is found than we return the larger element
    if (base_plus_one < num_at_base)
        return numbers.at(base);
        //If a LARGER element is NOT found, then we recursively call the function again inside of itself but
        //we increment the base until we get to the end of the vector which is caught by our first IF statement.
    else
        return larger_left_right_recursive_helper_looking_forward(numbers, base + 1, base_plus_one);
}
//****************

//****************
//DONE
int check_for_biggest_side(int biggest_in_the_left, int biggest_in_the_right) {
    //When checking whether the left or right largest is bigger we are met with 4 cases
    //**** 4 Cases for Largest Left vs Largest Right ****
    //Case 1: The element found to be the largest on the right is bigger
    //than the one found on the left. Therefore, return the right
    if(biggest_in_the_right > biggest_in_the_left)
        return biggest_in_the_right;
        //Case 2: The element found to be the largest on the left is bigger
        //than the one found on the right. Therefore, return the left
    else if(biggest_in_the_left > biggest_in_the_right)
        return biggest_in_the_left;
        //Case 3: Neither found a larger element on the left or the right
        //Therefore, return that no larger element was found represented by 0
    else if(biggest_in_the_right == 0 && biggest_in_the_left == 0)
        return  0;
        //Case 4: The element found to be the largest and on the right
        //and the left are equal
        //Therefore, we can return EITHER one. It does NOT matter
        //whether we return the element on the left of the one on the right since
        //they both are equivalent.
    else if(biggest_in_the_left == biggest_in_the_right)
        return biggest_in_the_right;

}
//****************

//****************
//DONE
void larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n) {
    int last_element_in_vector = numbers.size() - 1;
    int zeroSetter = 0;
    //Start by initializing the base to be zero
    int base = numbers.size() - n;
    int base_plus_one = numbers.at(base);
    //************
    //** LAST ELEMENT OF VECTOR CASE **
    //************
    //This IF statement will run for the LAST element of the vector
    if(base == last_element_in_vector) {
        //Then search for the largest element looking only to the LEFT
        //The function largest_left_recursive_helper specifically only
        //searches for elements that are greater to the LEFT.
        int largest_element_left_of_last_setter = largest_left_recursive_helper(numbers, base, base_plus_one);
        int largest_element_left_of_last = largest_element_left_of_last_setter;
        //Then return a pushback to the vector of the largest element that was found
        return result.push_back(largest_element_left_of_last);
    }
        //************
        // ** FIRST ELEMENT OF VECTOR CASE **
        //************
        //This ELSE IF statement will run for the FIRST element of the vector
        //We know it will be the first element because we set the base equal to be zero
    else if(base == zeroSetter) {
        //Call a helper function that will allow us to look from the start of the list to the end
        //from left to right and look for the largest element
        int element_found_forward_from_start_setter = larger_left_right_recursive_helper_looking_forward(numbers, base, base_plus_one);
        int element_found_forward_from_start = element_found_forward_from_start_setter;
        //Add the value that was just found for being the largest element to the right of the vector
        result.push_back(element_found_forward_from_start);
    }
    //************
    // ** EVERY OTHER ELEMENT OF VECTOR CASE **
    //************
    //IF WE find neither the first or last element then we continue by looking at both the
    //left and right elements of each element in the vector to determine the largest
    if(base != zeroSetter && base != last_element_in_vector) {
        int biggest_in_the_left = largest_left_recursive_helper(numbers, base, base_plus_one);
        int biggest_in_the_right = larger_left_right_recursive_helper_looking_forward(numbers, base, base_plus_one);
        //Using another helper function we can compare the bigger element found from reading to the left
        //of the current element to the biggest element found when reading to the right of the current element in the vector
        //That is why we only pass into the biggest number found on the left and the biggest number found on the right
        //because those are the only two things that this function is comparing
        result.push_back(check_for_biggest_side(biggest_in_the_left, biggest_in_the_right));
    }
    //Recursively return the solution but increment the size using n-1
    larger_left_right_recursive(numbers, result, n-1);
}
//****************


//****************
//DONE
int increasing_sequences_iterative(std::vector<int> &numbers) {
    //It is important to note that arrays cannot change size at runtime.
    //Hence why vectors work out better
    //The vector here is only used to store the size of the sequences
    std::vector<int> storeValueOfBiggestSequence;
//Every single number is its own sequence of 1
//When you find a number bigger than the one before it
//Then you get a sequence of two
//For instance look at this vector
//***** 10 20 1 0 ******
// 10 20 = sequence of two
// 1 = sequence of 1
// 0 = sequence of 1
//Therefore, this is a PROOF that the sequence must always be at least 1
//and NEVER less unless the vector is empty.
    int biggestSequence_iterative = 1;
//This first FOR loop is used to detect the size of the sequences
    for(int i = 0; i < numbers.size() - 1; i++) {
        if(numbers.at(i+1) >= numbers.at(i)) {
            //IF a number is found to be greater than the number before it
            //Add 1 to the biggest sequence int
            //This means the sequence
            biggestSequence_iterative++;
        }
        else {
            //This resets the biggest sequence to be 1
            biggestSequence_iterative = 1;
        }
        storeValueOfBiggestSequence.push_back(biggestSequence_iterative);
    }
//Next, a FOR loop is used to compare the size of the sequences
//we found in the last loop to see which one is the biggest
//Initially set the biggest element to be the first value of the vector.
    int biggestSequenceFromVector = storeValueOfBiggestSequence.at(0);
//Next, iterate through the vector that is storing the sequences.
//Remember, these 'sequences' are sizes of sequences detected by
//the first for loop
    for(int j = 1; j < storeValueOfBiggestSequence.size(); j++)
    {
        //We start iterating from the second element because of the fact
        //we already set biggestSequenceFromVector equal to the
        //first element. Therefore we are saying v.at(1) > v.at(0)
        if(storeValueOfBiggestSequence.at(j) > biggestSequenceFromVector)
        {
            //Each time a element is found to be bigger than the last it
            //updates to be the element stored in biggestSequenceFromVector
            //This confirms that once we get to the end of the list
            //we will have the biggest element
            biggestSequenceFromVector = storeValueOfBiggestSequence.at(j);
        }
    }
//At the end, we simply return the biggestSequenceFromVector
//that we just found from our previous FOR loop by
//searching through the vector and updating the biggest element
    return biggestSequenceFromVector;
}
//****************


//****************
//DONE
int helper_seq_rec(std::vector<int> &numbers, int startIdx) {
    if(startIdx == numbers.size() - 1) {
        return 0;
    }
    //This next if statement is what is used to determine if a number is bigger
    //than the one before it, or equal to
    //The "loop" comes from incrementing StartIdx inside
    //of the helper function call down below.
    //This is a recursion
    if(numbers.at(startIdx + 1) >= numbers.at(startIdx)) {
        //We increment startIdx by one, but also we return a + 1 on the end
        //which carries a 1 over the return functions
        //to eventually be added together
        //when we return this function with a +1 we are ultimately
        //increasing the workingWith variable
        return helper_seq_rec(numbers, startIdx + 1) + 1;
    }
    //We then add return one. To understand look at this vector
    //**** 1 2 1 0 ****
    //1 2 = sequence of 2
    //However, it only returns 1 for 1 being greater
    //than 2. Therefore, it would only return 1 currently.
    //So we have to add a return one to help it understand the ending number
    //is apart of the sequence even if what comes next is less than it
    return 1;
}

//****************
//Done
int increasing_sequences_recursive(std::vector<int> &numbers, int startIdx) {
    //StartIdx begins at 0
    //If there is only 1 element in the vector then we
    //say the increasing sequence is 1
    if(startIdx >= numbers.size() - 1) {
        return 1;
    }
    //set a variable of int datatype to be equal to the helper recursive call
    //Although we do not do it here inside of the helper function
    //StartIdx increments each time it is passed so it allows for each element
    //to be checked
    int workingWith = helper_seq_rec(numbers, startIdx);
    int biggest = increasing_sequences_recursive(numbers, startIdx + 1);
    if(workingWith > biggest) {
        //This is NOT a comparison. It is setting the right equal to the left
        biggest = workingWith;
    }
    //Return the biggest sequence that was found

    //This number will be a integer since we set it equal to
    //a recursive function of int datatype that has
    //valid return values
    return biggest;
}
//****************


//****************
//DONE
//Reads from the file into the vector
void read_numbers(std::string fileName, std::vector<int> &v) {
    std::ifstream ifs(fileName);
    int element;
    while (ifs >> element) {
        v.push_back(element);
    }

}
//****************

//****************
//DONE
//Created simply in order to test the output of any vector
void test_output_vector(std::vector<int> &v) {
    for (auto i : v) {
        std::cout << i << " ";

    }

}//****************
