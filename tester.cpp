// #include "tester.hpp"

// #include <string>
// #include <iostream>
// #include <fstream>

// using namespace std;

// void tester::testGameBoard() {
//     string boardFile;
//     string printResults;
//     int height;
//     int width;
//     double probability;

//     GameBoard past;
//     GameBoard current;
//     GameBoard future;
//     int count = 1;
//     int h;
//     int w;
//     double p;

//     welcome();
//     boardFile = boardChoice();

//     if (boardFile != "") {
//         current.createFileBoard(boardFile);
//         copyBoard(current, past);
//         copyBoard(current, future);
//     } else {
//         cout << "Please enter the height of the board(Enter a positive integer): ";
//         cin >> h;
//         cout << "Please enter the width of the board(Enter a positive integer): ";
//         cin >> w;
//         cout << "Please enter the probability (Enter a decimal 0 to 1): ";
//         cin >> p;
//         current.createRandomBoard(h, w, p);
//     }


//     printResults = resultsChoice();
    


//     if (printResults == "d") {
//         while(keepGoing()){
//             system("pause");
//             current.displayBoard(count);
//             ++count;
//         } 
//     } else if (printResults == "d"){
//         while(keepGoing()){
//             current.displayBoard(count);
//             ++count;
//         } 
//     } else {
//         printToTextFile(past, current, future, printResults);
        
//     }
// }

// void tester::testClassic() {

// }

// void tester::testAll() {
//     testClassic();
// }

// void tester::testGameModeClassicBoundries() {
//     GameBoard board;
//     welcome();
//     cout << "This is Classic Mode" << endl;
//     //board.createFileBoard("test1.txt");
//     board.createRandomBoard(6,6,0.5);
//     ClassicMode::AddClassicBoundaries(board);
//     cout << "what the user sees" << endl;
//     board.displayBoard(1);
//     cout << "Actual Boundries" << endl;
//     board.displayEntireBoard();
// }

// void tester::testGameModeDonutBoundries() {
//     GameBoard board1;
//     welcome();
//     cout << "This is Donut Mode" << endl;
//     board1.createFileBoard("test1.txt");
//     //board1.createRandomBoard(6,6,0.5);
//     board1.displayBoard(1);
//     DonutMode::AddDonutBoundaries(board1);
//     cout << "what the user sees" << endl;
//     board1.displayBoard(1);
//     cout << "Actual Boundries" << endl;
//     board1.displayEntireBoard();
// }

// void tester::testGameModeMirrorBoundries() {
//     GameBoard board1;
//     GameBoard board2;
//     welcome();
//     cout << "This is Mirror Mode" << endl;
//     board1.createFileBoard("test1.txt");
//     board2.createFileBoard("test1.txt");
//     //board1.createRandomBoard(6,6,0.5);
//     board1.displayBoard(1);
//     MirrorMode::AddMirrorBoundaries(board1);
//     cout << "what the user sees" << endl;
//     board1.displayBoard(1);
//     cout << "Actual Boundries" << endl;
//     board1.displayEntireBoard();
//     cout << "Update board\n" << endl;
//     GameModes::UpdateBoard(board1, board2);
//     MirrorMode::AddMirrorBoundaries(board2);
//     cout << "what the user sees" << endl;
//     board2.displayBoard(1);
//     cout << "Actual Boundries" << endl;
//     board2.displayEntireBoard();
// }

