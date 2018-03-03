#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char getRandChar(int capitols, int specials);

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

  srand(time(0));

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
      dataType = 1;
    }
    // check for special chars specification
    if(argc == 4) {
      // check arg validity
      if(!(*argv[3] == 'Y' || *argv[3] == 'N')) {
        printf("Third Argument must be 'Y' or 'N'\n");
        return EXIT_FAILURE;
      } else {
        specialChars = 1;
      }
    }
  }
  // if not specified set to default of no
  else {
    dataType = 0; // default N
    specialChars = 0; // default N
  }

  // create an array of character to represent the password
  char password[numChars]; // password to be set, allocate the size
  // Loop through the specified number of characters specified by the user
  // Call generate randChar
  for(int i = 0; i < numChars; i ++) {
    // here we will call the function to return a random char and add to string
    password[i] = getRandChar(dataType, specialChars); // set each index to separate call
    // pass in capitols and special characters
  }

  printf("Your randomly generated password is: \n");
  for(int i = 0; i < numChars; i++) {
    printf("%c", password[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}

/**
 * Return a random lowercase letter or number character, unless user specifies
 *  that they want uppercase letters and/or special characters
 * @param capitols Used if user specifies that they want capitols (int = 1)
 * @param specials Used if user specifies that they want special chars (int = 1)
 * @return Randomly generated character that meets specification
*/
char getRandChar(int capitols, int specials) {
  // check to see if user specified using captiol and special letters
  if(capitols == 1 && specials == 1) {
    // use a switch to decide to randomly decide what to do
    int whatToDo = rand() % 3; // generated a nuber between 1 and 3 for reference in switch
    int randSpecial = rand() % 4; // do calculation now so we can skip " character if needed
    switch(whatToDo) {
      case 0: // use a captiol
              return 'A' + (rand() % 26);
      case 1: // use a special char
              if(randSpecial == 0) { // make sure we don't return " character
                return '!'; // default case
              }
              else if (randSpecial != 0) {
                return '!' + randSpecial + 1; // skip " character
              }
      case 2: // use neither
              return 'a' + (rand() % 26);
    }
  }
  // only specials specified
  else if(capitols == 0 && specials == 1) {

  }
  // only capitols specified
  else if(capitols == 1 && specials == 0) {

  }
  // nothing specified
  else {
    return 'a' + (rand() % 26);
  }
}
