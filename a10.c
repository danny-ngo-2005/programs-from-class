
#include <stdio.h>
#include "getdouble.h"

// Author Name: Danny Ngo
// Date Created: 10/04/2024
// Purpose:The purpose of this assignment is to use recursion functions to
// calculate integers that range between the first and second input the
// user initiates. In order, the folowing outputs will be given:
// Count, Sum, Product, Power, and GCD. Error check is also
// given to ensure proper input of user.

void displayInteger(int first, int last) {
    if (first > last) {
      printf("\n");
        return;
    }
    printf("%d ", first);
    displayInteger(first+1, last);
}
//Prints each number from the first to the last on increments of 1 then stops when the first input
//is greater than the last.

int displaySum(int first, int last) {
  if (first > last) {
    return 0;
    }
    return first + displaySum(first +1, last);
  }
//returns the sum of all numbers by using the recursion function, similar to displayIntegers.

int displayProduct(int first, int last) {
  if (first > last) {
    return 1;
  }
  return first * displayProduct(first +1, last);
}
//Returns the product of all numbers by using the recursion function, similar to displaySum.

int displayPow(int first, int last) {
  if (last == 0) {
    return 1;
  }
   return first * displayPow(first, last-1);
}
//Returns the power by using first as the base and last as the exponent. Keeps multiplying by the first
//last times. Once last == 0, return 1 so that the last digit is multiplied by 1 to preserve its
//status.

int displayGCD(int first, int last) {
if (last == 0) return first;
return displayGCD(last, first % last);
  }
//Using the modulus, continues the modulus until first is 0, then returns the GCD.

int main() {
  printf("Please enter two positive integers, separated by a space, the first smaller than the second\n");

  int first = (int)getdouble();
  int last = (int)getdouble();
  //Defines two of the user's input.

  if (last < first) {
    printf("Error in input: %d is not smaller than %d\n", last, first);
    return 1;
    } else if (last <= 0 || first <= 0) {
     printf("Error in input: Only positive values must be inputted");
     return 1;
      }
  //Error checking to ensure user does not input either first is greater than last, or either numbers
  //are negative.

     printf("Displaying the integers from %d to %d: ", first, last);
     displayInteger(first,last);

     printf("Displaying the sum of the integers from %d to %d: %d \n"
            , first, last, displaySum(first, last));

     printf("Displaying the product of the integers from %d to %d: %d \n"
            , first, last, displayProduct(first, last));

     printf("Displaying the power of the integers from %d to %d: %d \n"
            , first, last, displayPow(first, last));

     printf("Displaying the GCD(Greatest common denominator) of the integers from %d to %d: %d \n"
            , first, last, displayGCD(first, last));

  //From 69-82, clarifies and uses the functions for each respected displayed calculation.
  }

