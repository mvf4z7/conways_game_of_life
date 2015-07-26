
#include "GameOfLife.h"
#include "utility.h"

#include <cstdlib>


void GameOfLife::setCellCharacters(const string &liveCellCharacter, const string &deadCellCharacter)
{
    Cell::setCharacters(liveCellCharacter, deadCellCharacter);
}

void GameOfLife::generateSeed(const string &seedFile)
{
    // Generate a random seed if a seed file is not provided.
    if(seedFile == "")
    {
        m_grid.generateRandomSeed();
        return;
    }
    
    // If the provided file does not exists, generate a random seed.
    if(!utility::fileExists(seedFile))
    {
        cout << "The provided seed file does not exist!!!" << endl;
        cout << "A random seed has been generated in place of the file." << endl << endl;
        
        utility::pressEnter("Press enter to continue...");
        
        m_grid.generateRandomSeed();
        return;
    }
    
    // If an existing file is provided, attemp to load it.
    // Load a random seed if the file is improperly formatted.
    if(m_grid.loadSeedFile(seedFile))
    {
        cout << "Seed file has been been successfully loaded!" << endl;
    }
    else
    {
        cout << "Invalid seed file format!!!" << endl;
        cout << "The file should contain a rectangular matrix consisting entirely of the characters 0 and 1." << endl;
        cout << "A 0 represents a dead cell and a 1 represents a living cell." << endl << endl;
        
        cout << "A random seed has been generated in place of the file." << endl << endl;
        
        utility::pressEnter("Press enter to continue...");

        m_grid.generateRandomSeed();
    } 
}

void GameOfLife::run(unsigned int millisDelay)
{
    // If the grid is empty then there is nothing to print to screen
    if(m_grid.empty())
    {
        cout << "A seed grid has not been generated or loaded. "
             << "Call the generateSeed method before running the evolution." << endl;
        return;
    }
    
    // Display the seed grid
    m_grid.print();
    
    utility::pressEnter("\nPress enter to begin the evolution...");
    
    while(true)
    {
        m_grid.updateGrid();
        utility::clearScreen();
        m_grid.print();
        
        utility::delay(millisDelay);
    }
}

GameOfLife::Args GameOfLife::parseArgs(int argc, const char * argv[])
{
    string fileOption = "-f";
    string delayOption = "-d";
    
    GameOfLife::Args args;
    
    for(int i = 1; i + 1 < argc; i++)
    {
        if(argv[i] == fileOption)
        {
            args.seedFile = argv[i + 1];
            i++;
        }
        else if (argv[i] == delayOption)
        {
            if(utility::isPositiveNumber(argv[i + 1]))
            {
                unsigned int num = atoi(argv[i + 1]);
                args.millisDelay = num;
                i++;
            }
        }
    }
    
    return args;
}



