#include <stdio.h>
#include <stdlib.h>

/**
 * This takes in the arguments from the command line and interprets them,
 * and then proceeds to print out a randomly generated password based on params
 * @param argc Integer value of number of arguments typed into command prompt
 * @param argv Character array representing values taken in by program
 * @return EXIT_SUCCESS for successful completion or EXIT_FAILURE
*/
int main(int argc, char** argv) {

  int numChars; // Integer value representing the desired length of the users pass
  int dataType; // value 1 means user specified capitol, else 0
  int specialChars; // value 1 means user specified special characters

  // check for proper formatting of call to function
  if(argc < 2 || argc > 4) { // Make sure the user calls the function with parameters
    printf("Proper Usage: \n");
    printf("./RandomPassGen #PassLength <'Y' or 'N'> <'Y' or 'N'>\n");
    printf("    ...     (Desired Length) (Capitols?) (Specials Characters?) \n");
    return EXIT_FAILURE;
  }
  numChars = atoi(argv[1]); // The first value specified by the user is the password length
  // check for valid length input
  if(numChars < 1) {
    printf("Please specify a valid password length! \n");
    return EXIT_FAILURE;
  }
  // check if second argument was specified
  if(argc >= 3) {
    // check arg validity
    if(!(*argv[2] == 'Y' || *argv[2] == 'N')) {
      printf("Second Argument must be 'Y' or 'N'\n");
      return EXIT_FAILURE;
    } else {
      dataYpe = 1;
    }
    // check for special chars specification
    if(argc == 4) {
      specialChars == *argv[3]; // if specified set special chars to 3 arg
      // check arg validity
      if(!(specialChars == 'Y' || specialChars == 'N')) {
        printf("Third Argument must be 'Y' or 'N'\n");
        return EXIT_FAILURE;
      }
    }
  }
  // if not specified set to default of no
  else {
    dataType = 'N'; // default N
    specialChars = 'N'; // default N
  }

  // Loop through the specified number of characters specified by the user
  // Call generate randChar
  for(int i = 0; i < numChars; i ++) {

  }

  return EXIT_SUCCESS;
}

/**
 * Return a random lowercase letter or number character, unless user specifies
 *  that they want uppercase letters and/or special characters
 * @param capitols Used if user specifies that they want capitols (int = 1)
 * @param specials Used if user specifies that they want special chars (int = 1)
 * @return Randomly generated character that meets specification
*/
char* getRandChar(int capitols, int specials) {

}
