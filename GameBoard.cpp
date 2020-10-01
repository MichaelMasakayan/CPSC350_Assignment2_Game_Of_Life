#include "GameBoard.hpp"

#include <fstream>
#include <math.h>
#include <time.h>

#define MAX_PROBABILITY 1

GameBoard::GameBoard(string name) {   //Constructor if user inputs a file
    fileName = name;
    readFile();
}

GameBoard::GameBoard(int w, int h, double prob) {   //Constucotr is user wants a random board
    width = w;
    height = h;
    probability = prob;
    randomBoard();
}

void GameBoard::readFile() {
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        throw "Error opening " +  fileName + "for reading";
    } 

    inFile >> height;
    inFile >> width;

    int lineCounter = 0;
    board = new char*[height];
    string boardLine;

    inFile >> boardLine;
    while (inFile >> boardLine) {
        board[lineCounter] = new char[width];
        for (int i = 0; i < width; ++i){
            board[lineCounter][i] = boardLine[i];
        }
        lineCounter++;
    }
    inFile.close();

}

void GameBoard::randomBoard() {
    board = new char*[height];

    double threshold = probability > MAX_PROBABILITY ? MAX_PROBABILITY : probability;

    for (int y = 0; y < height; ++y) {
        board[y] = new char[width];
        for (int x = 0; x < width; ++x) {
            double randomize = (float)rand()/RAND_MAX;
            board[y][x] = randomize < threshold ? open : cell;
        }
    }
}

int getWidth(){

}
int getHeight();
void setWidth(int w);
void setHeight(int h);