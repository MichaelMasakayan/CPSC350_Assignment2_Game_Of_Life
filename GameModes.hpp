#ifndef _GAME_MODES_HPP_
#define _GAME_MODES_HPP_

#include <string>

class GameModes {
    public:
        GameModes();    //default constructor
        //GameModes();

    protected:
        int x;
        int y;
        int width;
        int height;
        const char cell = 'X';
        const char enpty = '-';

    private:


};

class ClassicMode : public GameModes {
    public:
        ClassicMode();
        static void AddClassicBoundaries(GameBoard& board1); //Add the ' -' for the boundry
        GameBoard UpdateClassic(GameBoard board);
        void askKeepGoing(); 

    private:
    

};

class MirrorMode : public GameModes {
    public:
        static void AddMirrorBoundaries(GameBoard& board1); 
        GameBoard UpdateClassic(GameBoard board);

    private:
};

class DonutMode : public GameModes {
    public:
        static void AddDonutBoundaries(GameBoard& board1);
        GameBoard UpdateDonut(GameBoard board);
}; 


#endif