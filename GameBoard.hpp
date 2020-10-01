#ifndef _GAME_BOARD_HPP_
#define _GAME_BOARD_HPP_

#include <string>

using namespace std;

class GameBoard {
    public:
        GameBoard(string name);
        GameBoard(int w, int h, double probability);

        void readFile();
        void randomBoard();

        int getWidth();
        int getHeight();
        void setWidth(int w);
        void setHeight(int h);

    private:
        int height;
        int width;
        char** board;
        string fileName;
        double probability;
        char open = '-';
        char cell = 'X';

    
};

#endif