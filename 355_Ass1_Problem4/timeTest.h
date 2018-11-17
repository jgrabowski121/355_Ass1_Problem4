//
//  timeTest.h
//  CS355Ass1
//
//  Created by Justin Grabowski on 11/14/18.
//  Copyright © 2018 Justin Grabowski. All rights reserved.
//
#include <ctime>



#ifndef timeTest_h
#define timeTest_h

class executionTimeTester {
   clock_t startClock;
   clock_t endClock;
   
public:
   
   executionTimeTester();
   
   //Set the startTime field to the current time
   void setStartClock();
   
   //Set the endTime field to the current time
   void setEndClock();
   
   /*
   * Return the differnece between startTime and endTime
   * Must call StartTime before endTime to get a valid result
   */
   double getTimeDiferenceSeconds();
};








#endif /* timeTest_h */
