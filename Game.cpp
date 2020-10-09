#include "Game.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;


/**************************************
 * setUpBoard
 * Sets up the game board and runs the game
 **************************************/
void Game::setUpBoard() {
    string boardFile;
    string printResults;
    string mode;

    GameBoard past;
    GameBoard current;
    GameBoard future;

    int count = 0;
    int height;
    int width;
    double probability;

    welcome();
    boardFile = boardChoice();

    if (boardFile != "") {
        current.createFileBoard(boardFile);
    } else {
        cout << "Please enter the height of the board(Enter a positive integer): ";
        cin >> height;
        cout << "Please enter the width of the board(Enter a positive integer): ";
        cin >> width;
        cout << "Please enter the probability (Enter a decimal 0 to 1): ";
        cin >> probability;
        current.createRandomBoard(height, width, probability);
    }
    
    past.createRandomBoard(current.getHeight() - 2, current.getWidth() - 2, 1);
    future.createRandomBoard(current.getHeight() - 2, current.getWidth() - 2, 0);
    GameModes::copyBoard(current, future);
    

    mode = modeChoice();
    updateBoundaries(mode, current);
    GameModes::updateBoard(current, future);
    updateBoundaries(mode, future);

    printResults = resultsChoice();

    if (printResults == "p") {
        while(checkPastAndFuture(past, future) && checkCurrent(current)){
            current.displayBoard(++count);
            GameModes::copyBoard(current, past);
            GameModes::copyBoard(future, current);
            GameModes::updateBoard(current, future);
            updateBoundaries(mode, future);

            // System("pause") does not work for mac, only works for windows
            chrono::seconds dura(1);
            this_thread::sleep_for( dura );
        } 
    } else if (printResults == "d"){
        do {
            current.displayBoard(++count);
            GameModes::copyBoard(current, past);
            GameModes::copyBoard(future, current);
            GameModes::updateBoard(current, future);
            updateBoundaries(mode, future);
        } while(keepGoing() && checkPastAndFuture(past, future) && checkCurrent(current));
        cout << "Done printing" << endl;
    } else {
        printToTextFile(past, current, future, printResults, mode);
    }
}
/**************************************
 * updateBoundaries
 * updates the correct boundaries for the 
 * designated game mode
**************************************/
void Game::updateBoundaries(string mode, GameBoard& current) {
    if (mode == "C") {
        ClassicMode::AddClassicBoundaries(current);
    } else if (mode == "D") {
        DonutMode::AddDonutBoundaries(current);
    } else if (mode == "M") {
        MirrorMode::AddMirrorBoundaries(current);
    }
}

/**************************************
 * printToTextFile
 * Prints the different generations of the board
 * to a text file
 **************************************/
void Game::printToTextFile(GameBoard& past, GameBoard& current, GameBoard& future, string printResults, string mode) {
    int generationCounter = 0;
    cout << "Printing..." << endl;
    while(checkPastAndFuture(past, future) && checkCurrent(current)) {
        current.printBoardText(printResults, ++generationCounter);
        GameModes::copyBoard(current, past);
        GameModes::copyBoard(future, current);
        GameModes::updateBoard(current, future);
        updateBoundaries(mode, future);
    }
    cout << "Done! The data has printed to " << printResults << endl;
}

/**************************************
 * welcome
 * print a welcome message to the user
 * when they start the program
**************************************/
void Game::welcome() {
    cout << "~~~~~~~~~ Welcome to the Game of Life ~~~~~~~~~\n\n" << endl;
}

/**************************************
 * boardChoice
 * Ask the user whether they want to input their own 
 * text file or want to create a random board
**************************************/
string Game::boardChoice() {
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

/**************************************
 * resultsChoice
 * Ask the user whether they want to input their own 
 * text file or want to create a random board
**************************************/
string Game::resultsChoice() {
    string answer;
    cout << "Would you like to: " << endl << "T: Print the results on a text file\n" << "D: Display the board by generation in the console.\n" << "P: Pause inbetween each generation\n" << endl;
    cin >> answer;
    if (answer == "T" || answer == "t") {
        cout << "What would you like to name the test file: ";
        cin >> answer;
        return answer;
    } else if (answer == "D" || answer == "d") {
        return "d";
    } 
    return "p";
}

/**************************************
 * modeChoice
 * Ask the user what game mode they want to play
**************************************/
string Game::modeChoice()
{
    string gameMode;

    cout << "Please select which game mode you would like to play: "<<endl;
    cout << "C: Classic Boundries " << endl;
    cout << "D: Donut Boundries " << endl;
    cout << "M: Mirror Boundries" << endl;
    cin >> gameMode;

    
    while(gameMode != "C" && gameMode != "c" && gameMode != "D" && gameMode != "d" && gameMode != "m" && gameMode != "M")
    {
        cout << "Please enter a valid input: " << endl;
        cout << "C: classic Boundries " << endl;
        cout << "D: Donut Boundries " << endl;
        cout << "M: Mirror Boundries" << endl;
        cin >> gameMode;
    }

    if(gameMode == "M" || gameMode == "m" ) {
        return "M";
    } else if (gameMode == "D" || gameMode == "d" ){
        return "D";
    }
    return "C";
}

/**************************************
 * keepGoing
 * Ask the user whether they want to print another 
 * generation of the board
**************************************/
bool Game::keepGoing() {
    bool keepGoing;
    string answer;
    cout << "Do you want to print the next generation? (y or n)" << endl;
    cin >> answer;

    if (answer == "Y" || answer == "y") {
        return true;
    } 
    return false;
}


/**************************************
 * checkPastAndFuture
 * Checks if the past and future version of the board 
 * are the same. This check is used to determine if the
 * boards are alternating between 2 versions.
 **************************************/
 bool Game::checkPastAndFuture(GameBoard &past, GameBoard &future)
{
    for (int y = 1; y < past.getHeight() - 1; ++y)
    {
        for (int x = 1; x < past.getWidth() - 1; ++x)
        {
            if (past.getCharAt(y, x) != future.getCharAt(y, x))
            {
                return true;
            }
        }
    }
    return false;
}

 /**************************************
 * checkCurrent
 * Check is the current board has any cels that are alive.
 * This check is used to determine when to stop printing 
 * generations of the board.
 **************************************/
 bool Game::checkCurrent(GameBoard& current){
   for (int y = 1; y < current.getHeight()-1; ++y) {
        for (int x = 1; x < current.getWidth()-1; ++x) {
            if(current.getCharAt(y, x) == 'X') {
                return true;
            }
        }
   }
   return false;
}

