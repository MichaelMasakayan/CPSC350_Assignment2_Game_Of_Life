#include <iostream>
#include <fstream>
#include <string>

#include "FileReader.hpp"


using namespace std;

void welcome();
string boardChoice();

int main()
{   
    string boardFile;
    char** gameBoard;

    welcome();
    boardFile = boardChoice();
    if (boardFile != "") {
        FileReader reader(boardFile);
        gameBoard = reader.readFile();
        cout << "Game board read in" << endl;
    } //else if {
    //     ;// create random file
    // }

    
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 7; ++i)
            cout << gameBoard[i][j];
    }

    return 0;
}


void welcome() {
    cout << "~~~~~~~~~ Welcome to the Game of Life ~~~~~~~~~\n\n" << endl;
}

string boardChoice() {
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

