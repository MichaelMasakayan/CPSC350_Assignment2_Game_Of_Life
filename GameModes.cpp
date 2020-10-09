#include "GameBoard.hpp"
#include "GameModes.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


GameModes::GameModes() {}

/**************************************
 * AddClassicBoundaries
 * set the boundaries of the classic mode
 * board to '-'
**************************************/
void ClassicMode::AddClassicBoundaries(GameBoard& board1) { 
    for (int i = 0; i < board1.getHeight(); ++i) {
        for (int j = 0; j < board1.getWidth(); ++j){
            if (i == (board1.getHeight() - 1) || i == 0 || j == (board1.getWidth() - 1) || j == 0) {
                board1.setBoardValue(i, j, '-');
            }
        }
    }
}

/**************************************
 * AddDonutBoundaries
 * Set the boundaries of the donut mode
 * board to the corrent values from the
 * opposite side of the board
**************************************/
void DonutMode::AddDonutBoundaries(GameBoard& board1) {
    char temp;
    for (int i = 0; i < board1.getHeight(); ++i) {
        temp = '\0';
        for (int j = 0; j < board1.getWidth(); ++j) {
            if (i == 0 && j == 0) { // Corners
                temp = board1.getCharAt(board1.getHeight() - 2, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if (i == 0 && j == board1.getWidth() - 1) {
                temp = board1.getCharAt(board1.getHeight() - 2, 1);
                board1.setBoardValue(i, j, temp);
            } else if (i == board1.getHeight() - 1  && j == 0) {
                temp = board1.getCharAt(1, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if (i == board1.getHeight() - 1 && j == board1.getWidth() - 1) {
                temp = board1.getCharAt(1, 1);
                board1.setBoardValue(i, j, temp);
            } else if (i == 0) {  // Sides
                temp = board1.getCharAt(board1.getHeight() - 2, j);
                board1.setBoardValue(i, j, temp);
            } else if (j == 0) {
                temp = board1.getCharAt(i, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if(i == board1.getHeight() - 1) {
                temp = board1.getCharAt(1, j);
                board1.setBoardValue(i, j, temp);
            } else if (j == board1.getWidth() - 1) {
                temp = board1.getCharAt(i, 1);
                board1.setBoardValue(i, j, temp);
            } 
        }
    }
}

/**************************************
 * AddMirrorBoundaries
 * Set the boundaries of the mirror mode
 * board to the mirrored char of the edge
 * values around the board
**************************************/
void MirrorMode::AddMirrorBoundaries(GameBoard& board1) {
    char temp;
    for (int i = 0; i < board1.getHeight(); ++i) {
        temp = '\0';
        for (int j = 0; j < board1.getWidth(); ++j) {
            if (i == 0 && j == 0) { // Corners
                temp = board1.getCharAt(1,1);
                board1.setBoardValue(i, j, temp);
            } else if (i == 0 && j == board1.getWidth() - 1) {
                temp = board1.getCharAt(1, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if (i == board1.getHeight() - 1  && j == 0) {
                temp = board1.getCharAt(board1.getHeight() - 2, 1);
                board1.setBoardValue(i, j, temp);
            } else if (i == board1.getHeight() - 1 && j == board1.getWidth() - 1) {
                temp = board1.getCharAt(board1.getHeight() - 2, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if (i == 0) {  // Sides
                temp = board1.getCharAt(1, j);
                board1.setBoardValue(i, j, temp);
            } else if (j == 0) {
                temp = board1.getCharAt(i, 1);
                board1.setBoardValue(i, j, temp);
            } else if(i == board1.getHeight() - 1) {
                temp = board1.getCharAt(board1.getHeight() - 2, j);
                board1.setBoardValue(i, j, temp);
            } else if (j == board1.getWidth() - 1) {
                temp = board1.getCharAt(i, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } 
        }
    }
}   

/**************************************
* copyBoard
* Copy the current board to a new board 
* to allocate space for update
**************************************/
void GameModes::copyBoard(GameBoard& original, GameBoard& copy) {
    char temp;
    for (int y = 0; y < original.getHeight(); ++y) {
        for (int x = 0; x < original.getWidth(); ++x) {
            copy.setBoardValue(y, x, original.getCharAt(y, x));
        }
    }
}

/**************************************
 * UpdateBoard
 * Takes the current game board and applies
 * those updates to the next board (next generation)
**************************************/
void GameModes::updateBoard(GameBoard& current, GameBoard& next) {
    unsigned int neighbors;
    char temp;
    for (int y = 1; y < current.getHeight() - 1; ++y) {
        for (int x = 1; x < current.getWidth() - 1; ++x) {
            neighbors = getAdjacentCellCount(current, x, y);
            if (neighbors <= 1 || neighbors >= 4) {
                next.setBoardValue(y, x, '-');
            } else if (neighbors == 2) {
                temp = current.getCharAt(y, x);
                next.setBoardValue(y, x, temp);
            } else if (neighbors == 3) {
                next.setBoardValue(y, x, 'X');
            }
        }
    }
}

/**************************************
 * getAdjacentCellCount
 * private method that gets the cells 
 * surrounding a specified location
**************************************/
int GameModes::getAdjacentCellCount(GameBoard& board1, int x, int y) {
    int count = 0;
    for(int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (!(i == y && j == x) && board1.getCharAt(i, j) == 'X'){
                count++;
            }
        }
    }
    return count;
}
