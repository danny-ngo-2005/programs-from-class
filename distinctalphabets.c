#include <stdio.h>

// Author Name: Danny Ngo
// Date Created: 10/15/2024
// Purpose:The purpose of this assignment is to identify the numbers of distinct
// alphabet characters in a line of sentences that the user inputs.
// Note that case-sensitive is not applicable in this program. i.e:
// a and A are the same index.

//27 Letters in the alphabet. 26 is given since 0 is considered a value.
#define SIZE 26

//Gives the user instructions on how to proceed with the program.
void displayInstructions() {
    printf("This program will count the letters of the alphabet.\n");
    printf("Type several sentences, or use input redirection to input a file.\n");
    printf("To exit program, enter EOF (end of file) by pressing Ctrl-Z(Windows) or Ctrl-D(Mac).\n");
}

void countCharacters(int letters[]) {
int character;

//Acts like a scanner function; Goes through each character in the line until EOF.
//For both uppercase and lowercase, as long as the characters are within range of a - z,
//the value for that index will increment by 1. Any special case characters are ignored.
while ((character = getchar()) != EOF) {

  if (character >= 'a' && character <= 'z') {
    letters[character - 'a']++;
}
  if (character >= 'A' && character <= 'Z') {
    letters[character - 'A']++;
    }
  }
 }

 //Displays the output for the number of characters range from a-z. A for loop is used
 //for the printf for each letter.
void outputResults(int letters[], int size) {
  printf("The character counts are:\n");
  for (int i = 0; i < size; i++) {
    printf("%c\t%d\n", 'a' + i, letters[i]);
  }
}

int main() {

  //Defines and initializes array variable letters with all values set to 0.
  int letters[SIZE]={0};

  //Executes the functions required for the program to run.
  displayInstructions();
  countCharacters(letters);
  outputResults(letters, SIZE);
  }
