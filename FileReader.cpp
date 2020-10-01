#include "FileReader.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

FileReader::FileReader(string file) {
    fileName = file;
}

char** FileReader::readFile() {
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        throw "Error opening " +  fileName + "for reading";
    } 

    inFile >> height;
    inFile >> width;

    int lineCounter = 0;
    char** gameBoard = '\0';
    gameBoard = new char*[height];
    string boardLine;

    inFile >> boardLine;
    while (inFile >> boardLine) {
        gameBoard[lineCounter] = new char[width];
        for (int i = 0; i < width; ++i){
            gameBoard[lineCounter][i] = boardLine[i];
        }
        lineCounter++;
    }
    inFile.close();

    return gameBoard;
}