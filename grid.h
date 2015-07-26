
#ifndef GRID_H
#define GRID_H

#include "Cell.h"

#include <string>
#include <vector>


//----------------------------------------
/* _________________
 /                 \
 |    Grid Class   |
 \_________________/
 
 
 PURPOSE: Consists of a 2D vector and the methods required to implement
          Conway's game of life. Each element in the 2D vector is a Cell 
          object. Also contains the functionality to load a random seed 
          grid or to import one from a file.
 
 */

class Grid
{
private:
    
    /*
     Purpose: Primary data structure for implementing Conway's Game of life.
              Most of the Grid class methods operate on this member variable
              in some way.
    */
    vector<vector<Cell> > m_currentGrid;
    
    /* 
     Purpose: Determines whether a Cell should be in the alive or dead state
              for the next iteration. This determination is based upon the
              rules for Conway's game of life. These rules are explained in
              depth in the readme.txt file provided with this program.
     Parameters: cell is the cell object for which the next state (alive or
                 dead) is determined
     Returns: A new Cell object that has its state and coordinates properly
              set for the next iteration
    */
    Cell getNextCellState(const Cell &cell);
    
    /*
     Purpose: Calculates the number of alive neighbors of a particular Cell
              object. A Cell's neighbors are considered to be the 8 cells
              surrounding it. If one of the 8 neighbors of a cell is outside
              of the bounds of the grid then that neighbor is considered to
              be dead.
     Parameters: cell is the Cell for which the number of alive neighbors is
                 to be counted
     Returns: The number of alive neighbors for the parameter cell
    */
    int numberOfAliveNeighbors(const Cell &cell);
    
public:
    
    /*
     Purpose: Default constructor
    */
    Grid() : m_currentGrid() {}
    
    /*
     Purpose: Default destructor
    */
    ~Grid(){}
    
    /*
     Purpose: Load a txt file to be used as a seed for the implementation of
              Conway's game of life. This file should consist of a rectangular
              grid of only the characters 0 and 1. A zero represents a dead
              Cell object and a 1 represents a live Cell object.
     Parameters: filepath is the path to the txt seed file to be loaded
     Postcondition: If the seed file is succesfully loaded then the member variable
                    m_currentGrid reflects the grid in the seed file. If the seed
                    file fails to load then m_currentGrid remains in the state it
                    was in before the attempt to load a seed file.
     Returns: True if the seed file is succesfully loaded.
    */
    bool loadSeedFile(const string &filepath);
    
    /*
     Purpose: Generates and loads a random seed grid into the member variable
              m_currentGrid
     Postcondition: The member variable m_currentGrid consists of a randomly 
                    loaded 2D group of Cell objects, with their states set to 
                    live or dead.
    */
    void generateRandomSeed();
    
    /*
     Purpose: Iterates over all of the Cell objects contained in the member
              variable m_currentGrid and updates their state based upon the rules
              for Conway's game of life. Once this method is called the old state
              of the grid is lost.
     Postcondition: The states of the Cell objects contained in m_CurrentGrid are 
                    all set to the next state.
    */
    void updateGrid();
    
    /*
     Purpose: A check for whether or not member variable m_currentGrid contains
              any cell objects.
     Returns: True if m_currentGrid is empty
    */
    bool empty();
    
    /*
     Purpose: Prints the Cells contained in m_currentGrid to the console. The character
              represenations of live and dead cells can be set to anything but have default
              values. See the Cell class documentation for more information on these values.
    */
    void print();
};


#endif
