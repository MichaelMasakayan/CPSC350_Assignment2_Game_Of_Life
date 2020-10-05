#ifndef _GAME_BOARD_HPP_
#define _GAME_BOARD_HPP_

#include <string>

using namespace std;

class GameBoard {
    public:
        GameBoard();
        ~GameBoard();
        void createFileBoard(string fileName);
        void createRandomBoard(int height, int width, double probability);
        void displayBoard();
        void setHeight(int height);
        void setWidth(int width);
        int getHeight();
        int getWidth();
        static string boardChoice();
        static void welcome();
        void setValue(int position);
        void setBoardValue(int height, int width, char value);
        void displayEntireBoard();
        char getCharAt(int i,int j);


    private:
        char** board;
        const char OPEN = '-';
        const char CELL = 'X';
        int height;
        int width;
};

#endif