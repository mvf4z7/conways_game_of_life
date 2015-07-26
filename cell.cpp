
#include "Cell.h"


/*
 Setting the default values for the static Cell class members that store the string
 representations of live and dead cells. C++ requires that non const static class members
 be initialized outside of the class definition.
*/
string Cell::m_liveCharacter = "1"; // Black box with white border
string Cell::m_deadCharacter = "0"; // Solid white box.

string Cell::getLiveCharacter()
{
    return Cell::m_liveCharacter;
}

string Cell::getDeadCharacter()
{
    return Cell::m_deadCharacter;
}

void Cell::setCharacters(const string &liveCharacter, const string &deadCharacter)
{
    Cell::m_liveCharacter = liveCharacter;
    Cell::m_deadCharacter = deadCharacter;
}

void Cell::setAlive()
{
    m_alive = true;
}

int Cell::x() const
{
    return m_xValue;
}

int Cell::y() const
{
    return m_yValue;
}

void Cell::setDead()
{
    m_alive = false;
}

bool Cell::isAlive() const
{
    return m_alive;
}

ostream& operator<<(ostream& os, const Cell& cell)
{
    if(cell.isAlive())
    {
        os << Cell::getLiveCharacter();
    }
    else
    {
        os << Cell::getDeadCharacter();
    }
    
    return os;
}