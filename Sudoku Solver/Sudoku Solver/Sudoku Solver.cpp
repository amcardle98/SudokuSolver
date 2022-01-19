/*
    Name: Alex Mcardle
    Course: Discrete Structures 3710
    Subject: Final Exam programming assignment
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

bool Solve(int board[9][9]);

bool Valid(int board[9][9], int number, vector<int>position);

int sudoku_grid[9][9] = {
        {7, 8, 0, 4, 0, 0, 1, 2, 0},
        {6, 0, 0, 0, 7, 5, 0, 0, 9},
        {0, 0, 0, 6, 0, 1, 0, 7, 8},
        {0, 0, 7, 0, 4, 0, 2, 6, 0},
        {0, 0, 1, 0, 5, 0, 9, 3, 0},
        {9, 0, 4, 0, 6, 0, 0, 0, 5},
        {0, 7, 0, 3, 0, 0, 0, 1, 2},
        {1, 2, 0, 0, 0, 7, 4, 0, 0},
        {0, 4, 9, 2, 0, 6, 0, 0, 7}
};

vector<int> Find_empty(int board[9][9])
{
    int boardSize = sizeof(board[0]) / sizeof(board[0][0]);

    vector<int> pos;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == 0) {
                pos.push_back(i);
                pos.push_back(j);
                return pos;
            }
        }
    }

    return (vector<int>)0;
}

bool Solve(int board[9][9])
{
    int boardSize = sizeof(board[0]) / sizeof(board[0][0]);
    int row;
    int col;
    vector<int>pos = Find_empty(board);
    //cout << boardSize;

    if (pos == (vector<int>)0) {
        return true;
    }
    else {
        row = pos[0];
        col = pos[1];

    }

    for (int i = 1; i < 10; i++) {
        if (Valid(board, i, pos)) {
            board[row][col] = i;

            if (Solve(board)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

bool Valid(int board[9][9], int number, vector<int> position)
{
    int boardSize = sizeof(board[0]) / sizeof(board[0][0]);

    //checking row
    for (int i = 0; i < boardSize; i++) {
        if (board[position[0]][i] == number && position[1] != i) {
           return false;
        }
    }

    //checking column
    for (int i = 0; i < boardSize; i++) {
        if (board[i][position[1]] == number && position[0] != i) {
            return false;
        }
    }

    //check box
    int box_y = position[0] / 3;
    int box_x = position[1] / 3;

    for (int i = box_y * 3; i < (box_y*3 + 3); i++) {
        for (int j = box_x * 3; j < (box_x*3 + 3); j++){
            if (board[i][j] == number && (i != position[0] && j != position[1])) {
                return false;
            }
        }
    }

    return true;
}

int Print_board(int board[9][9])
{
    for (int i = 0; i <= sizeof(board); i++) {
        if (i % 3 == 0 and i != 0) {
            cout << "-------------------\n";
        }

        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 and j != 0) {
                cout << " | ";
            }

            if (j == 8) {
                cout << board[i][j];
                cout << '\n';
            }
            else {
                cout << board[i][j];
            }
        }
    }

    return 0;
}


int main()
{
    Print_board(sudoku_grid);
    Solve(sudoku_grid);
    cout << "----------------------------------\n";
    cout << "Calculating.";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".\n";
    Sleep(500);
    cout << "\n";
    Print_board(sudoku_grid);

    
    return 0;
}



