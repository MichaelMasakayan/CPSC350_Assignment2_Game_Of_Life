#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <string>
#include "GameBoard.hpp"


#define MAX_PROBABILITY 1

using namespace std;

/**************************************
 * GameBoard()
 * Default constructor for GameBoard class
 **************************************/
GameBoard::GameBoard() {   // Default constructor
    height = 0;
    width = 0;
}

GameBoard::GameBoard(int h, int w) {
    height = h;
    width = w;
}
/**************************************
 * ~GameBoard()
 * Destructor
 **************************************/
GameBoard::~GameBoard() {   // Destructor
    for (int y = 0; y < height; ++y) {
        delete [] board[y];
    }
    delete [] board;
}


/**************************************
 * createFileBoard
 * Open the file the user input and create a board from the text file that they 
 * provided. 1st line is the height(int), 2nd line is the widt(int), and the rest of
 * the file is the game board(char**)
**************************************/
void GameBoard::createFileBoard(string fileName) {
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        throw "Error opening " +  fileName + "for reading";
    }

    inFile >> height;
    inFile >> width;

    height += 2;
    width += 2;

    board = new char*[height];
    string boardLine;

    for (int y = 0; y < height; ++y) {
        board[y] = new char[width];
        if (y > 0) {
            inFile >> boardLine;
        }
        for (int x = 0; x < width; ++x) {
            if (x == 0 || y == 0 || y == height - 1 || x == width - 1) {
                board[y][x] = '0';
            } else {
                board[y][x] = boardLine[x-1];
            }    
        }
    }
    inFile.close();
}

/**************************************
 * createRandomBoard
 * The user provided the height width and the probability 
 * of how many cells start off on the board. The cells are 
 * randomly placed on the board
**************************************/
void GameBoard::createRandomBoard(int h, int w, double probability) {
    height = h + 2;
    width = w + 2;

    board = new char*[height];

    double threshold = probability > MAX_PROBABILITY ? MAX_PROBABILITY : probability;

    for (int y = 0; y < height; ++y) {
        board[y] = new char[width];
        for (int x = 0; x < width; ++x) {
            double randomize = (float)rand()/RAND_MAX;
            if(y == height - 1 || x == width - 1 || x == 0 || y == 0) {
                board[y][x] = '0';
            } else {
                board[y][x] = randomize < threshold ? CELL : OPEN;
            }
        }
    }
}

/**************************************
 * displayBoard
 * Goes through the 2d array and prints
 * only the part of the board the user sees
**************************************/
void GameBoard::displayBoard(int generation) {
    cout << "\ngeneration " << generation << endl;
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            cout << board[y][x];
        }
        cout << endl;
    }
}

/**************************************
 * printBoardText
 * Goes through the 2d array and prints
 * the board out to a textfile
**************************************/
void GameBoard::printBoardText(string printResults, int generation) {
    ofstream outfile;
    outfile.open(printResults, ios::app);
    if(!outfile) {
        cout << "File did not open" << endl;
    }
    outfile << "\ngeneration " << generation << endl;
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            outfile << board[y][x];
        }
        outfile << endl;
    }

    outfile.close();

}

/**************************************
 * displayEntireBoard
 * Used as a tester method to display the entire
 *  board including the boundaries around the board
**************************************/
void GameBoard::displayEntireBoard() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cout << board[y][x];
        }
        cout << endl;
    }
}

char GameBoard::getCharAt(int i, int j) {
    return board[i][j];
}

void GameBoard::setHeight(int height) {
    this->height = height;
}

void GameBoard::setWidth(int width) {
    this->width = width;
}


void GameBoard::setBoardValue(int height, int width, char value) {
    board[height][width] = value;
}

int GameBoard::getHeight() {
    return height;
}

int GameBoard::getWidth() {
    return width;
}
