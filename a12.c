#include <stdio.h>

// Author Name: Danny Ngo
// Date Created: 10/15/2024
// Purpose:The purpose of this assignment is to modify and interact with a pointer.
// This program will create a pointer, display its address, dereference the pointer,
// and lastly use the dereference to change the value of a variable.

int main() {

  //Initializes and defines the variables given.
  char letter = 'm';
  int number = 360;
  double decimal = 123.456;

  //Initializes the address, and then defines it with the variables given above.
  char *pLetter = &letter;
  int *pNumber = &number;
  double *pDecimal = &decimal;

  //Displays the address of each of the pointers by using %p
  printf("Address of letter (char): %p\n", (void*)pLetter);
  printf("Address of number (int): %p\n", (void*)pNumber);
  printf("Address of decimal (double): %p\n\n", (void*)pDecimal);

  //Displays the values inside of the pointers using their respective data types
  printf("Value of letter: %c\n", *pLetter);
  printf("Value of number: %d\n", *pNumber);
  printf("Value of decimal: %.2f\n\n", *pDecimal);

  //Each value in the pointers will be added by 3.
  printf("Now my program is adding 3 to the 3 dereferenced pointers: \n\n");
  *pLetter += 3;
  *pNumber += 3;
  *pDecimal += 3;

  //From lines 38-44, the code is essentially the same as lines 22-29, with exception
  //to lines 43-45 in which the variables are used instead, as since the pointer
  //is dereferenced to include 3, the variable also changes as well to its respected
  //value, in this case: "p", "363" and "126.46".
  printf("Updated value of letter: %c\n", *pLetter);
  printf("Updated value of number: %d\n", *pNumber);
  printf("Updated value of decimal: %.2f\n\n", *pDecimal);

  printf("Final letter: %c\n", letter);
  printf("Final number: %d\n", number);
  printf("Final decimal: %.2f\n", decimal);

  return 0;
  }