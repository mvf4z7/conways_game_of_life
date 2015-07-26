

#include "GameOfLife.h"


int main(int argc, const char * argv[]) {
    
    GameOfLife game;
    
    // Parse command line arguments.
    GameOfLife::Args args = GameOfLife::parseArgs(argc, argv);
    
    // Setting cells characters to unicode strings. If you only see question
    // marks printed to the screen then comment this line out or set to parameters
    // to non-unicode characters.
    game.setCellCharacters("\u25A1", "\u25A3");
    
    // Load seed from a file, if provided.
    // Otherwise generate a random seed.
    game.generateSeed(args.seedFile);
    
    // Run the simulation!
    game.run(args.millisDelay);
    
    return 0;
}
