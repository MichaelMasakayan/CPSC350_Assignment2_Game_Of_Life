#include "tester.hpp"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void tester::testGameBoard(int h,int w,double p)
{
 string boardFile;
    int height;
    int width;
    double probability;

    GameBoard board;
    board.welcome();
    boardFile = board.boardChoice();

    if (boardFile != "") {
        board.createFileBoard(boardFile);
    } else {
        cout << "Please enter the height of the board(Enter a positive integer): ";
        cin >> h;
        cout << "Please enter the width of the board(Enter a positive integer): ";
        cin >> w;
        cout << "Please enter the probability (Enter a decimal 0 to 1): ";
        cin >> p;
        board.createRandomBoard(h, w, p);
    }
    board.displayBoard();
}

void tester::testClassic()
{

}

void tester::testAll()
{
    testClassic();
}

void tester::testGameModeClassicBoundries()
{
    GameBoard board;
    board.welcome();
    cout << "This is Classic Mode" << endl;
    //board.createFileBoard("test1.txt");
    board.createRandomBoard(6,6,0.5);
    ClassicMode::AddClassicBoundaries(board);
    cout << "what the user sees" << endl;
    board.displayBoard();
    cout << "Actual Boundries" << endl;
    board.displayEntireBoard();
}

void tester::testGameModeDonutBoundries()
{
    GameBoard board1;
    board1.welcome();
    cout << "This is Donut Mode" << endl;
    board1.createFileBoard("test1.txt");
    //board1.createRandomBoard(6,6,0.5);
    board1.displayBoard();
    DonutMode::AddDonutBoundaries(board1);
    cout << "what the user sees" << endl;
    board1.displayBoard();
    cout << "Actual Boundries" << endl;
    board1.displayEntireBoard();
}

void tester::testGameModeMirrorBoundries()
{
    GameBoard board1;
    board1.welcome();
    cout << "This is Mirror Mode" << endl;
    board1.createFileBoard("test1.txt");
    //board1.createRandomBoard(6,6,0.5);
    board1.displayBoard();
    MirrorMode::AddMirrorBoundaries(board1);
    cout << "what the user sees" << endl;
    board1.displayBoard();
    cout << "Actual Boundries" << endl;
    board1.displayEntireBoard();
}