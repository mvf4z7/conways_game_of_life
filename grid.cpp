
#include "Grid.h"
#include "utility.h"

#include <iostream>
#include <fstream>
#include <random>


bool Grid::loadSeedFile(const string &filepath)
{
    ifstream file(filepath);
    string line;
    
    vector<vector<Cell> > tempGrid;
    
    // Used to count the number of lines that have been read from the file.
    // This will also be equal to the x-coordinate of the created cell.
    int x = 0;
    
    // If anything other than a 0 or 1 is read from the file then this variable
    // will be set false and the function will return false.
    bool validFormat = true;
    
    // Iterate over lines in the file
    while(getline(file, line) && validFormat)
    {
        vector<Cell> row;
        
        // Iterate over each character in the line
        for(int y = 0; y < line.length(); y++)
        {
            Cell cell(x, y);
            
            switch(line[y])
            {
                case '0':
                    cell.setDead();
                    row.push_back(cell);
                    break;
                    
                case '1':
                    cell.setAlive();
                    row.push_back(cell);
                    break;
                                        
                default:
                    cout << "Invalid Character: " << line[y] << endl;
                    validFormat = false;
            }
        }
        
        tempGrid.push_back(row);
        
        x++;
    }
    
    // Return false if seed file did not contain any characters
    if(tempGrid.empty())
    {
        return false;
    }
    
    // Checking that all rows of the grid contain the same number of Cells
    int firstRowSize = tempGrid[0].size();
    for(int i = 1; i < tempGrid.size() && validFormat; i++)
    {
        if(tempGrid[i].size() != firstRowSize)
        {
            validFormat = false;
        }
    }
    
    
    if(!validFormat)
    {
        return false;
    }
    else
    {
        m_currentGrid = tempGrid;
        return true;
    }
}

void Grid::generateRandomSeed()
{
    random_device seed;
    mt19937 generate(seed());
    uniform_int_distribution<int> gridDimension(50, 100); //Limit the number of rows and columns to values between 50 and 100
    int gridRows = gridDimension(generate);
    int gridCols = gridDimension(generate);
    
    // Limit generator to values between 1 and 10.
    // If the value is less than or equal to the THRESHOLD value, a live cell will be generated.
    // Otherwise, a dead cell is generated. 
    uniform_int_distribution<int> cellState(1, 10);
    const int THRESHOLD = 4;
    
    vector<vector<Cell> > tempGrid;
    
    for(int i = 0; i < gridRows; i++)
    {
        vector<Cell> row;
        
        for(int j = 0; j < gridCols; j++)
        {
            Cell cell(i, j);
            
            int state = cellState(generate);
            
            if(state <= THRESHOLD)
            {
                cell.setAlive();
                row.push_back(cell);
            }
            else
            {
                cell.setDead();
                row.push_back(cell);
            }
        }
        
        tempGrid.push_back(row);
    }
    
    m_currentGrid = tempGrid;
}

void Grid::updateGrid()
{
    vector<vector<Cell> > nextGrid(m_currentGrid);
    
    for(int i = 0; i < m_currentGrid.size();  i++)
    {
        for(int j = 0; j < m_currentGrid[i].size(); j++)
        {
            Cell nextState = getNextCellState(m_currentGrid[i][j]);
            nextGrid[i][j] = nextState;
        }
    }
    
    m_currentGrid = nextGrid;
}

Cell Grid::getNextCellState(const Cell &cell)
{
    Cell nextState(cell.x(), cell.y());
    
    int aliveNeighbors = numberOfAliveNeighbors(cell);
    
    if(!cell.isAlive())
    {
        
        if(aliveNeighbors == 3)
        {
            // Cell comes to life through reproduction
            nextState.setAlive();
            return nextState;
        }
        else
        {
            // Cell remains dead
            nextState.setDead();
            return nextState;
        }
    }
    
    
    // Cell is currently alive
    
    if(aliveNeighbors == 2 || aliveNeighbors == 3)
    {
        // Cell lives on to next generation
        nextState.setAlive();
        return nextState;
    }
    
    // Cell dies due to under population or overcrowding
    nextState.setDead();
    return nextState;
}

int Grid::numberOfAliveNeighbors(const Cell &cell)
{
    int aliveNeighbors = 0;
    
    int x = cell.x();
    int y = cell.y();
    
    // Check direct left neighbor
    if(y != 0)
    {
        if(m_currentGrid[x][y - 1].isAlive())
            aliveNeighbors += 1;
    }
    
    // Check top left neighbor
    if(x != 0 && y != 0)
    {
        if(m_currentGrid[x - 1][y - 1].isAlive())
            aliveNeighbors += 1;
    }
    
    // Check direct up neighbor
    if(x != 0)
    {
        if(m_currentGrid[x - 1][y].isAlive())
            aliveNeighbors += 1;
    }
    
    // Check top right neighbor
    if(x != 0 && y + 1 <= m_currentGrid[x - 1].size() - 1)
    {
        if(m_currentGrid[x - 1][y + 1].isAlive())
            aliveNeighbors += 1;
    }
    
    // Check direct right neighbor
    if(y + 1 <= m_currentGrid[x].size() - 1)
    {
        if(m_currentGrid[x][y + 1].isAlive())
            aliveNeighbors += 1;
    }
    
    // Check bottom right neighbor
    if(x + 1 <= m_currentGrid.size() - 1 && y + 1 <= m_currentGrid[x+1].size())
    {
        if(m_currentGrid[x + 1][y + 1].isAlive())
            aliveNeighbors += 1;
    }
    
    // Check direct down neighbor
    if(x + 1 <= m_currentGrid.size() - 1)
    {
        if(m_currentGrid[x + 1][y].isAlive())
            aliveNeighbors += 1;
    }
    
    // Check bottom left neighbor
    if(x + 1 <= m_currentGrid.size() - 1 && y != 0)
    {
        if(m_currentGrid[x + 1][y - 1].isAlive())
            aliveNeighbors += 1;
    }
    
    return aliveNeighbors;
}

bool Grid::empty()
{
    return m_currentGrid.empty();
}

void Grid::print()
{
    for(int i = 0; i < m_currentGrid.size(); i++)
    {
        for(int j = 0; j < m_currentGrid[i].size(); j++)
        {
            cout << m_currentGrid[i][j];
        }
        
        cout << endl;
    } 
}









