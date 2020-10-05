#include <iostream>
#include <fstream>
#include <string>

#include "GameBoard.hpp"
#include "GameModes.hpp"
#include "tester.hpp"

using namespace std;


string boardChoice();

int main()
{
    //tester::testGameModeClassicBoundries();
    //tester::testGameBoard(3,4,.4);
    //tester::testGameModeDonutBoundries();
    tester::testGameModeMirrorBoundries();
   
    return 0;
}
