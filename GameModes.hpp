#ifndef _GAME_MODES_HPP_
#define _GAME_MODES_HPP_

// #include "GameBoard.hpp"

#include <string>

class GameModes {
    public:
        GameModes();    //default constructor
        static void copyBoard(GameBoard& original, GameBoard& copy);
        static void updateBoard(GameBoard& current, GameBoard& next);

    protected:
        int x;
        int y;
        int width;
        int height;

    private:
        static int getAdjacentCellCount(GameBoard& board1, int x, int y); 
        


};

class ClassicMode : public GameModes {
    public:
        ClassicMode();
        static void AddClassicBoundaries(GameBoard& board1); //Add the ' -' for the boundry

    private:
    

};

class MirrorMode : public GameModes {
    public:
        static void AddMirrorBoundaries(GameBoard& board1); 

    private:
};

class DonutMode : public GameModes {
    public:
        static void AddDonutBoundaries(GameBoard& board1);
}; 


#endif