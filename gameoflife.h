
#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "Grid.h"

class GameOfLife
{
private:
    /*
     Purpose: Object used to represent the 2D grid structure that
              implements Conway's Game of Life. See Grid class
              documentation for more information.
    */
    Grid m_grid;
    
public:
    /*
     Purpose: Default constructor
    */
    GameOfLife() : m_grid() {}
    
    /*
     Purpose: Default destructor
    */
    ~GameOfLife(){}
    
    /*
     Purpose: Sets the characters used to represent live and dead
              cells when they are output to console. The parameters
              are string types in order to allow unicode characters
              to be used.
     Parameters: liveCellCharacter is character used to represent live cells
                 deadCellCharacter is character used to represent dead cells
    */
    void setCellCharacters(const string &liveCellCharacter, const string &deadCellCharacter);
    
    /*
     Purpose: Loads a seed grid of live and dead cells into the member
              variable m_grid. Either a seed is randomly generated or 
              a seed file can be loaded if provided. The seed file should be
              a txt file consisting of only 0s and 1s. The 0s will be interpreted
              as dead cells while the 1s will be interpreted as live cells.
              If any other characters are recognized or an invalid file name 
              is provided, then a random seed is generated in place of the file.
     Parameters: seedFile is the filepath to the txt seed file
    */
    void generateSeed(const string &seedFile = "");
    
    /*
     Purpose: Begins the evolution process. The function generateSeed should
              be called before this function.
     Parameters: millisDelay is the millisecond delay between cell generations
     Returns: If run method is called before a grid has been generated then the 
              the function will return before the evolution is run.
    */
    void run(unsigned int millisDelay = 100);
    
    /*
     Purpose: A struct used to store the command line arguments passed to the program.
     Members: seedFile is the name of the seedFile passed to the program
              millisDelay is the delay between cell generations
    */
    typedef struct Args
    {
        Args(): seedFile(""), millisDelay(100) {}
        string seedFile;
        unsigned int millisDelay;
        
    } Args;
    
    /*
     Purpose: function used to parse command line arguments passed to the program
     Options: -f used to pass the file name of a seed file
              -d used to pass the millisecond delay between cell generations
    */
    static Args parseArgs(int argc, const char * argv[]);
};


#endif
