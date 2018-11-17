//
//  main.cpp
//  355_Ass1_Problem4
//
//  Created by Justin Grabowski on 11/17/18.
//  Copyright © 2018 Justin Grabowski. All rights reserved.
//

#include <iostream>
#include "timeTest.h"
#include <exception>

#include <chrono>

//Function declarations

/*
 * Performs references to elements
 *  of the array passed to the function
 * @param numReferences: the number of references made
 * @param int* array[] the array to test on
 */
void function1(unsigned numReferences, int* array[]);

/*
 * Performs references to elements
 *  of the array passed to the function using
 *  the storage mapping function and pointer arithmetic
 * @param numReferences: the number of references made
 * @param int* array[] the array to test on
 */
void function2(unsigned numReferences, int* array[]);


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
        function1(1000, arrayOne);
    }
    timeTest.setEndClock();
    
    std::cout << "Time to execute function2 "
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
        function2(1000, arrayOne);
    }
    timeTest.setEndClock();
    
    std::cout << "Time to execute function3 "
    <<  ITERATION
    << " iterations: "
    << std::fixed
    << (timeTest.getTimeDiferenceSeconds()*1000)<< " ms\n";
    
    std::cout << "Time to execute function2 1 iteration: "
    << std::scientific
    << (timeTest.getTimeDiferenceSeconds()/100000) * 1000
    << " ms\n\n";
    
    //----------------
    
    return 0;
}


void function1(unsigned numReferences, int* array[])
{
    int arrayOne[100][100];
    int arrayTwo[100][100];
    
    for (size_t i = 0; i < 100; ++i)
        for(size_t j = 0; j < 100; ++j)
        {
            arrayOne[i][j] = rand() % INT_MAX;
        }
    
    
}

void function2(unsigned numReferences, int* array[])
{
    
}
