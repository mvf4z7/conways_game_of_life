
#include "utility.h"

#include <fstream>
#include <iostream>
#include <time.h>


#if defined(unix) || defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__APPLE__)
    #ifndef __NIX__
        #define __NIX__
    #endif
    #include <unistd.h>

#elif defined(_WIN32) || defined(_WIN64)
    #ifndef __WINDOWS__
        #define __WINDOWS__
    #endif
    #include <windows.h>

#endif


namespace utility
{
    bool fileExists(const string &filename)
    {
        ifstream f(filename.c_str());
        
        if(f.good())
        {
            f.close();
            return true;
        }
        else
        {
            f.close();
            return false;
        }
    }
   
    void delay(unsigned int millis)
    {
        #ifdef __NIX__

            // Function parameter must be in microseconds;
            usleep(millis * 1000);
        
        #elif defined __WINDOWS__

            Sleep(millis);
        
        #else
        
            cout << "Uknown operating system detected." << endl;
            cout << "Unable to execute function:   utility::delay(int millis)" << endl;
        
        #endif
    }
    
    void clearScreen(unsigned int numberOfLines)
    {
        string newLines(numberOfLines, '\n');
        cout << newLines;
    }
    
    bool isPositiveNumber(const string &str)
    {
        if(str.empty())
        {
            return false;
        }
        
        string::const_iterator it = str.begin();
        
        while (it != str.end() && isdigit(*it))
        {
            ++it;
        }
        
        return it == str.end();
    }
    
    void pressEnter(const string &message)
    {
        cout << message;
        string str;
        getline(cin, str);
    }
    
}


