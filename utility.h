

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
using namespace std;

namespace utility
{
    /*
     Purpose: Checks whether or not a given file exists
     Returns: true if the file exists
    */
    bool fileExists(const string &filename);
    
    /*
     Purpose: Supsends the calling thread for a desired
              number of milliseconds
     Parameters: millis is the length of the delay in milliseconds
    */
    void delay(unsigned int millis);
    
    /*
     Purpose: Prints the indicated number of newline characters
              to the console, effectively clearing the screen
     Parameters: numberOfLines is the number of newline characters to be printed to console
    */
    void clearScreen(unsigned int numberOfLines = 20);
    
    /*
     Purpose: Determines whether or not the provided string is
              is an postive Arabic Numeral (i.e. 0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
     Returns: true if the string is in fact one of the arabic numerals listed above
    */
    bool isPositiveNumber(const string &str);
    
    /*
     Purpose: Prints the provided message to the console and requires that the
              user press the Enter key to continue
     Parameters: message is the message output to console
    */
    void pressEnter(const string &message);
}

#endif
