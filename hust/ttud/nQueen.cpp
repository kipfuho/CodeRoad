/*
Description
Given a chess board N x N on which there are K being placed in some cells. Compute the number of solutions to place other N - K queens in other cells such that among N queens on the board, no two queens attack each other.
A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.

Input
Line 1: contains a positive integer N (1 <= N <= 12)
Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A
Output
Write the number of solutions

Example
Input 
4
0 1 0 0
0 0 0 0
0 0 0 0
0 0 1 0
Output
1


Input 
5
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Output 
2
*/

#include<bits/stdc++.h>

using namespace std;

int n;
int totalSolution = 0;
int preQueen[12];
int queen[12]; // represent row i_th column queen is

bool check(int column, int row){
    for(int i = 0; i < n; i++){
        if(i == column) continue;
        if(queen[i] == 0) continue;
        if(queen[i] == row) return false;
        if(abs(i - column) == abs(row - queen[i])) return false;
    }
    return true;
}

int TRY(int column){
    if(preQueen[column]){
        if(column == n - 1) totalSolution++;
        else TRY(column + 1);
    }
    else{
        for(int i = 1; i <= n; i++){
            if(check(column, i)){
                if(column == n - 1){
                    totalSolution++;
                    return 1;
                }
                else{
                    queen[column] = i;
                    TRY(column + 1);
                    queen[column] = 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp; cin >> temp;
            if(temp == 1){
                if(queen[j] != 0){
                    cout << 0;
                    return 1;
                }
                queen[j] = i + 1;
                preQueen[j] = 1;
            }
        }
    }

    TRY(0);

    cout << totalSolution;
}