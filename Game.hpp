#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "GameBoard.hpp"
#include "GameModes.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>


class Game {
    public:
        void setUpBoard();
        void welcome();
        string boardChoice();
        string resultsChoice();
        string modeChoice();
        bool keepGoing();
        void printToTextFile(GameBoard& past, GameBoard& current, GameBoard& future, string printResults, string mode);
        void updateBoundaries(string mode, GameBoard& current);
        
        bool checkPastAndFuture(GameBoard& past,GameBoard& future);
        bool checkCurrent(GameBoard& current);

        // void userChoose();
        // void Play();
        // void userFileChoose();
        // string userFilePath;
        // void userUpdate();
        // void userBoundries();
        
        // static void updateToNextGeneration(GameBoard& p,GameBoard& c,GameBoard& f);
        
        
        // GameBoard past;
        // GameBoard current;
        // GameBoard future;


    private:
        int height;
        int width;
        double probability;
        // double gameMode = 1;
        // double userPause = 1;
        // double userFile = 1;

};
#endif