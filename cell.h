
#ifndef Cell_H
#define Cell_H

#include <string>
#include <iostream>
using namespace std;

//----------------------------------------
/* _________________
 /                 \
 |    Cell Class   |
 \_________________/
 
 
 PURPOSE: Each location on the game grid contains one Cell object. Each cell can assume one of
          two states, alive or dead. The state of a cell determines the image that is displayed
          on the screen when the cell is output to console.
 */


class Cell
{
private:
    
    /*
     Purpose: Stores the x-coordinate of the Cell.
    */
    int m_xValue;
    
    /*
     Purpose: Stores the y-coordinate of the Cell.
    */
    int m_yValue;
    
    /*
     Purpose: Flag for indicating whether or not the Cell is currently in the alive or dead state.
              True indicates alive, while false indicates dead.
    */
    bool m_alive;
    
    /*
     Purpose: Stores the "character" used to display a live cell. A string type is used so that unicode
              strings can be stored. Static class variables are used so that the live and dead cell 
              representations only have to be stored once for all instances of the Cell class. Furthermore,
              static variables make it easy to set the live and dead characters for all cells at once.
    */
    static string m_liveCharacter;
    
    /*
     Purpose: Stores the "character" used to display a dead cell.
    */
    static string m_deadCharacter;
    
    
public:
    
    /*
     Purpose: Default constructor
     Postconditions: m_xValue set to 0
                     m_yValue set to 0
                     m_alive set to false
    */
    Cell() : m_xValue(0), m_yValue(0), m_alive(false) {}
    
    /*
     Purpose: Auxiliary constructor
     Postconditions: m_xValue set to parameter x
                     m_yValue set to parameter y
                     m_alive set to false
    */
    Cell(int x, int y) : m_xValue(x), m_yValue(y), m_alive(false) {}
    
    /*
     Purpose: Auxiliary constructor
     Postconditions: m_xValue set to parameter x
                     m_yValue set to parameter y
                     m_alive set to parameter state
    */
    Cell(int x, int y, bool state) : m_xValue(x), m_yValue(y), m_alive(state) {}
    
    /*
     Purpose: Default destructor
    */
    ~Cell(){}
    
    /*
     Purpose: Sets the current state of the cell to alive
     Postcondition: The cell is in the alive state
    */
    void setAlive();
    
    /*
     Purpose: Sets the current state of the cell to dead
     Postcondition: The cell is in the dead state
    */
    void setDead();
    
    /*
     Purpose: Get the current state of the cell
     Returns: True if the cell is alive, false if the cell is dead
    */
    bool isAlive() const;
    
    /*
     Returns: The x-coordinate of the cell
    */
    int x() const;
    
    /*
     Returns: The y-coordinate of the cell
    */
    int y() const;
    
    
    /*
     Purpose: Get the "character" used to display a live cell when the cell is displayed
              on the screen.
     Returns: The character used to display a live cell, as a string
    */
    static string getLiveCharacter();
    
    /*
     Purpose: Get the "character" used to display a dead cell when the cell is displayed
              on the screen.
     Returns: The character used to display a dead cell, as a string
    */
    static string getDeadCharacter();
    
    /*
     Purpose: Set the characters used to display live and dead cells on screen
     Parameters: liveCharacter is the character that will be used to display a live cell
                 deadCharacter is the character that will be used to display a dead cell
    */
    static void setCharacters(const string &liveCharacter, const string &deadCharacter);
    
    /*
     Purpose: Overloading operator "<<", so that Cells may be easily printed to screen.
     Returns: If the cell is in the alive state then the live cell representation is
              returned. If the cell is in the dead state then the dead cell representation
              is returned.
    */
    friend ostream& operator<<(ostream& os, const Cell& cell);
};


#endif
