#ifndef _TESTER_HPP_
#define _TESTER_HPP_
#include <string>

#include "GameBoard.hpp"
#include "GameModes.hpp"

class tester {
    public:
        static void testAll();
        static void testClassic();
        static void testGameBoard(int h,int w,double p);
        static void testGameModeClassicBoundries();
        static void testGameModeDonutBoundries();
        static void testGameModeMirrorBoundries();

    private:

    

};
#endif