#ifndef _GAME_BOARD_HPP_
#define _GAME_BOARD_HPP_

#include <string>

using namespace std;

class GameBoard {
    public:
        GameBoard();
        GameBoard(int h, int w);
        ~GameBoard();
        void createFileBoard(string fileName);
        void createRandomBoard(int height, int width, double probability);

        
        
        void displayBoard(int generation);
        void displayEntireBoard();
        void printBoardText(string printResults, int generation);
        
        //Getters and Setters
        char getCharAt(int i,int j);
        int getHeight();
        int getWidth();
        void setHeight(int height);
        void setWidth(int width);
        void setValue(int position);
        void setBoardValue(int height, int width, char value);

    private:
        char** board;
        const char OPEN = '-';
        const char CELL = 'X';
        int height;
        int width;
        // int getAdjacentCellCount(GameBoard& board1, int x, int y);
};

#endif