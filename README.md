# 8queens
a small little C program that solves the eight queens problem recursively

the algorithm is the following:

the board is 8x8, so the maximum number of queens we can possibly place in the board is 8.

so if we ask to put 9 queens in an 8x8 board, we have reached a solution.

- call on queens = 0
- if queens > 8, write solution on screen and end execution
- else, start on the first line of the `queens` column
- if the line is < 8, store the current board config
- place a queen in that line
- mark all the squares that queen attacks (horizontally, vertically and diagonally)
- recurse the algorithm on queens = queens + 1
- recover the previously saved config
- mark the square line/queens as attacked
- move to the next line in the queens column

this program will, thus, present 92 possible solutions to the problem, with 80 being duplicates. more work could be done to verify these duplicates using dynamic programming.

## building

use gcc to build this program

```
$ gcc 8queens.c -o 8queens
```

## using

after compiling the program, just run it off the command line

```
$ ./8queens
```
