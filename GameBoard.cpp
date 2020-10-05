#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <string>
#include "GameBoard.hpp"


#define MAX_PROBABILITY 1

using namespace std;

GameBoard::GameBoard() {   // Default constructor
    height = 0;
    width = 0;
}

GameBoard::~GameBoard() {   // Destructor
    for (int y = 0; y < height; ++y) {
        delete [] board[y];
    }
    delete [] board;
}

int GameBoard::getHeight() {
    return height;
}

int GameBoard::getWidth() {
    return width;
}

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

void GameBoard::displayBoard() {
    //cout << "Height: " << height << "   Width: " << width << endl;
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            cout << board[y][x];
        }
        cout << endl;
    }
}

 void GameBoard::welcome() {
    cout << "~~~~~~~~~ Welcome to the Game of Life ~~~~~~~~~\n\n" << endl;
}

string GameBoard::boardChoice() {
    string answer;
    cout << "Would you like to input a board file? (y/n)" << endl;
    cin >> answer;
    if (answer == "y" || answer == "Y") {
        cout << "Please enter the board file: ";
        cin >> answer;
        return answer;
    }
    return "";
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