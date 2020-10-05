#include "GameBoard.hpp"
#include "GameModes.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


GameModes::GameModes()
{

}

void ClassicMode::AddClassicBoundaries(GameBoard& board1)
{ 
    for (int i = 0; i < board1.getHeight(); ++i) {
        for (int j = 0; j < board1.getWidth(); ++j){
            if (i == (board1.getHeight() - 1) || i == 0 || j == (board1.getWidth() - 1) || j == 0) {
                board1.setBoardValue(i, j, '-');
            }
        }
    }
}

void DonutMode::AddDonutBoundaries(GameBoard& board1)
{
    char temp;
    for (int i = 0; i < board1.getHeight(); ++i) {
        temp = '\0';
        for (int j = 0; j < board1.getWidth(); ++j) {
            if (i == 0 && j == 0) { // Corners
                temp = board1.getCharAt(board1.getHeight() - 2, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if (i == 0 && j == board1.getWidth() - 1) {
                temp = board1.getCharAt(board1.getHeight() - 2, 1);
                board1.setBoardValue(i, j, temp);
            } else if (i == board1.getHeight() - 1  && j == 0) {
                temp = board1.getCharAt(1, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if (i == board1.getHeight() - 1 && j == board1.getWidth() - 1) {
                temp = board1.getCharAt(1, 1);
                board1.setBoardValue(i, j, temp);
            } else if (i == 0) {  // Sides
                temp = board1.getCharAt(board1.getHeight() - 2, j);
                board1.setBoardValue(i, j, temp);
            } else if (j == 0) {
                temp = board1.getCharAt(i, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if(i == board1.getHeight() - 1) {
                temp = board1.getCharAt(1, j);
                board1.setBoardValue(i, j, temp);
            } else if (j == board1.getWidth() - 1) {
                temp = board1.getCharAt(i, 1);
                board1.setBoardValue(i, j, temp);
            } 
        }
    }
}

void MirrorMode::AddMirrorBoundaries(GameBoard& board1)
{
    char temp;
    for (int i = 0; i < board1.getHeight(); ++i) {
        temp = '\0';
        for (int j = 0; j < board1.getWidth(); ++j) {
            if (i == 0 && j == 0) { // Corners
                temp = board1.getCharAt(1,1);
                board1.setBoardValue(i, j, temp);
            } else if (i == 0 && j == board1.getWidth() - 1) {
                temp = board1.getCharAt(1, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if (i == board1.getHeight() - 1  && j == 0) {
                temp = board1.getCharAt(board1.getHeight() - 2, 1);
                board1.setBoardValue(i, j, temp);
            } else if (i == board1.getHeight() - 1 && j == board1.getWidth() - 1) {
                temp = board1.getCharAt(board1.getHeight() - 2, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } else if (i == 0) {  // Sides
                temp = board1.getCharAt(1, j);
                board1.setBoardValue(i, j, temp);
            } else if (j == 0) {
                temp = board1.getCharAt(i, 1);
                board1.setBoardValue(i, j, temp);
            } else if(i == board1.getHeight() - 1) {
                temp = board1.getCharAt(board1.getHeight() - 2, j);
                board1.setBoardValue(i, j, temp);
            } else if (j == board1.getWidth() - 1) {
                temp = board1.getCharAt(i, board1.getWidth() - 2);
                board1.setBoardValue(i, j, temp);
            } 
        }
    }
}   
