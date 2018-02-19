#include <stdio.h>
#include <stdlib.h>

/**
 * This takes in the arguments from the command line and interprets them,
 * and then proceeds to print out a randomly generated password based on params
 * @param argc Integer value of number of arguments typed into command prompt
 * @param argv Character array representing values taken in by program
 * @return 1 for successful completion or EXIT_FAILURE
*/
int main(int argc, char** argv) {

  int numChars; // Integer value representing the desired length of the users pass
  char dataType; // Char value either Y or N representing having capitol letters or not

  // check for proper formatting of call to function
  if(argc == 0) {
    printf("Proper Usage: \n");
    printf("./RandomPassGen #PassLength <'Y' or 'N' (Include Capitol Letters)> <'Y' or 'N' (Include Special Chars)>\n");
  }
  numChars = atoi(argv[0]); // The first value specified by the user is the password legnth

  return 0;
}
