//
// Justin Grabowski
// CS355
// Fall 2018
// November 10th 2018
// Instructor Ganchev G.
// main.cpp
// CS355Ass1_Problem4
// Language C++
//
// Purpose: This file tests the time taken for
// two-dimentional array element access

#include <iostream>
#include "timeTest.h"
#include <exception>

//Function declarations

/*
 * Performs references to elements
 *  of the array passed to the function
 * @param numReferences: the number of references made
 * @param int* array[] the array to test on
 */
void function1(unsigned arraySize, int* array[]);

/*
 * Performs references to elements
 *  of the array passed to the function using
 *  the storage mapping function and pointer arithmetic
 * @param numReferences: the number of references made
 * @param int* array[] the array to test on
 */
void function2(unsigned arraySize, int* array[], unsigned rowSize);


int main(int argc, const char * argv[]) {
    //Create executionTimeTester object
    executionTimeTester timeTest;
    unsigned ITERATION = 1000;
    const char ARRAY_SIZE = 100;
    
    //create a two dimentional array
    int **arrayOne;
    arrayOne = new int* [ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; ++i)
        arrayOne[i] = new int[ARRAY_SIZE];
    
    // initialize the array with random numbers
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
        {
            arrayOne[i][j] = rand() % INT_MAX;
        }
    
    // initialize random seed
    srand(time(NULL)); // implicit conversion is okay
    
    timeTest.setStartClock();
    for(size_t i = 0; i <= ITERATION; i++)
    {
        function1(ARRAY_SIZE, arrayOne);
    }
    timeTest.setEndClock();
    
    std::cout << "Time to execute function1 "
    <<  ITERATION
    << " iterations: "
    << std::fixed
    << (timeTest.getTimeDiferenceSeconds()*1000)
    << " ms\n";
    
    std::cout << "Time to execute function1 1 iteration: "
    << std::scientific
    << (timeTest.getTimeDiferenceSeconds()/100000) * 1000
    << " ms\n\n";
    
    //---------------
    
    timeTest.setStartClock();
    for(size_t i = 0; i <= ITERATION; i++)
    {
        function2(ARRAY_SIZE, arrayOne, ARRAY_SIZE);
    }
    timeTest.setEndClock();
    
    std::cout << "Time to execute function2 "
    <<  ITERATION
    << " iterations: "
    << std::fixed
    << (timeTest.getTimeDiferenceSeconds()*1000)<< " ms\n";
    
    std::cout << "Time to execute function2 1 iteration: "
    << std::scientific
    << (timeTest.getTimeDiferenceSeconds()/100000) * 1000
    << " ms\n\n";
    
    //----------------
    delete [] arrayOne; // delete the dynamic array
    return 0;
}


void function1(unsigned numReferences, int* array[])
{
    //int to store the recieved data for testing
    int temp;
    
    for (size_t i = 0; i < numReferences; ++i)
        for(size_t j = 0; j < numReferences; ++j)
        {
            temp = array[i][j];
        }
    
    
}

void function2(unsigned numReferences, int* array[], unsigned rowSize)
{
    unsigned long temp;
    int row_lb = 0;
    int col_lb = 0;
    for (size_t i = 0; i < numReferences; ++i)
        for(size_t j = 0; j < numReferences; ++j)
        {
            temp = (array[row_lb][col_lb] - (((row_lb * rowSize) + col_lb) * sizeof(int))
            + (((i * rowSize) + j) * sizeof(int)));
        }
}
