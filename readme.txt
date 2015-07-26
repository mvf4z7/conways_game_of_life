//
// Conway's Game of Life version 1.0
// Author: Mike Fanger
// November 13, 2014
//


This program implements a cellular automation "game" known as Conway's Game of Life. Conway's Game
of Life is not so much a game as it is a simulation. This is because the only player interaction it
requires is the input of an initial seed state. After the seed is provided, all later states are
determined by the computer based upon on a small set of rules.

The gamespace is a two-dimensional grid of squares (think chess board), in which each space on the grid
contains a cell. A cell may assume one of two states, alive or dead. For any one iteration of the
simulation, the following rules determine the next state of each cell.

    1. Any live cell with fewer than two live neighbours dies, as if caused by under population.
    2. Any live cell with two or three live neighbours lives on to the next generation.
    3. Any live cell with more than three live neighbours dies, as if by overpopulation.
    4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Each generation is a completely discrete step in the process of the evolution. Therefore, if a simulation
is currently in generation n, then the n + 1 state of a cell "c" is based upon the cell states of c's neighbours
during the nth generation.


COMPILING
---------

NOTE: This program should be compiled with a C++ 11 compliant compiler.

This program will compile and run on Linux, OSX and Windows. However, from my experience the console output
looks best on Linux and OSX.

For one, the Windows CMD doesn't seem to support unicode characters out of the box, and will print "?" in their
place. If you experience this issue, comment out line 16 in the file "main.cpp", as this sets the characters
used to represent live and dead cells in the console. When this line is commented out live and dead cell
representations will default to 1 and 0, respectively. These cell representations may also be set to any desired
value by changing the parameters of the setCellCharacters method on line 16 of main.cpp.

A second reason to avoid running this program on Windows is that the CMD window does not clear well, which
results in each grid generation scrolling by, rather than appearing to be updated in place. For all I know
I may be making a rookie mistake, but I did not run into this issue on Linux and OSX.


LOADING A SEED FILE
-------------------

A seed grid may be loaded from a file or randomly generated. To load a seed from a file, you must first
create the seed grid. The grid should be a two-dimensional rectangular array of 0s and 1s. The 0s
will be interpreted to be dead cells and the 1s will be interpreted to be live cells. The file should
be in plain text format (i.e. a .txt extension).

If the grid contains characters other than a 0 or 1, then the seed format will be considered invalid
and a random seed will be generated in place of the seed file. Furthermore, the seed file will be considered
invalid if it is not rectangular in shape (i.e. each row must contain the same number of cells).

An example grid file has been provided as gosper_glider_gun.txt. This file contains a well known seed
that will evolve infinitely, never resulting in a static grid state.

A seed file can be loaded by running the executable file with the -f option followed by a space and the
file path to the seed file.


example:

$./gameoflife.exe -f gosper_glider_gun.txt


If a seed filename is not provided at runtime, then a seed is randomly generated.


SETTING GENERATIONAL DELAY
--------------------------

After each cell state is computed for a new generation, the new grid is output to console. Due to the
ridiculous speed of modern computers, this output is unappealing to the eye if a small delay is not
input between each generational output. This delay was arbitratily set to 100 milliseconds (ms) by default,
as this value worked well on my development computer. The delay time can be set by running the executable
with the -d option followed by a positive integer value. The provided value is assumed to be in milliseconds.


example:

$./gameoflife.exe -d 150


DISCLAIMER
----------

The generational delay is implemented through the use of operating system dependent function calls. As stated
above, this program has compiled and run on Linux, OSX and Windows. But due to my lack of platform specific
programming experience, I cannot ensure that it will run on all versions of these operating systems.

This program has been succesfully run on the following operating system versions:

1) OSX 10.9.4
2) Ubuntu 12.04
3) Windows 7 (exact release unknown)










