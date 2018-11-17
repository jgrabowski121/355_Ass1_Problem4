//
//  timeTest.cpp
//  CS355Ass1
//
//  Created by Justin Grabowski on 11/14/18.
//  Copyright © 2018 Justin Grabowski. All rights reserved.
//

#include <stdio.h>
#include "timeTest.h"

//Constructor
executionTimeTester::executionTimeTester(){}

void executionTimeTester::setStartClock()
{
   startClock = clock();
}

void executionTimeTester::setEndClock()
{
   endClock = clock();
}

double executionTimeTester::getTimeDiferenceSeconds()
{
   return ((float) endClock - startClock ) / CLOCKS_PER_SEC;
}
