/*
Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)
Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:
Numbers of each row are distinct
Numbers of each column are distinct
Numbers on each sub-square 3 x 3 are distinct
Input
Each line i (i = 1, 2, ..., 9) contains elements of the i
th
 row of the Sudoku table: elements are numbers from 0 to 9 (value 0 means the empty cell of the table)
Output
Write the number of solutions found

Example
Input
0 0 3 4 0 0 0 8 9
0 0 6 7 8 9 0 2 3
0 8 0 0 2 3 4 5 6
0 0 4 0 6 5 0 9 7
0 6 0 0 9 0 0 1 4
0 0 7 2 0 4 3 6 5
0 3 0 6 0 2 0 7 8
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
Output
64
*/

#include<bits/stdc++.h>

using namespace std;

int totalSolution = 0;
int preSolution[9][9];
int solution[9][9];

/*
void printSol(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << solution[i][j];
        }
    }
}
*/

// row check
bool check1(int row, int column, int value){
    for(int i = 0; i < 9; i++){
        if(i == column) continue;
        if(solution[row][i] == value) return false;
    }
    return true;
}

// column check
bool check2(int row, int column, int value){
    for(int i = 0; i < 9; i++){
        if(i == row) continue;
        if(solution[i][column] == value) return false;
    }
    return true;
}

// block check
bool check3(int row, int column, int value){
    int rowBLock = row/3, colBlock = column/3;
    for(int i = 3*rowBLock; i < 3*rowBLock + 3; i++){
        for(int j = 3*colBlock; j < 3*colBlock + 3; j++){
            if(solution[i][j] == value) return false;
        }
    }
    return true;
}

void TRY(int x, int y){
    if(x == 9){
        totalSolution++;
        return;
    }

    if(preSolution[x][y] != 0){
        if(y == 8){
            TRY(x + 1, 0);
        }
        else TRY(x, y + 1);
    }
    else{
        for(int i = 1; i < 10; i++){
            if(check1(x, y, i) && check2(x, y, i) && check3(x, y, i)){
                solution[x][y] = i;
                if(y == 8){
                    TRY(x + 1, 0);
                }
                else TRY(x, y + 1);
                solution[x][y] = 0;
            }
        }
    }
    return;
}

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int temp; cin >> temp;
            preSolution[i][j] = solution[i][j] = temp;
        }
    }

    TRY(0, 0);
    cout << totalSolution;
}