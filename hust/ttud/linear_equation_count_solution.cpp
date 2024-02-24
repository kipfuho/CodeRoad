/**
Given a positive integer n and n positive integers a_1, a_2, ..., a_n
. Compute the number of positive integer solutions to the equation:
                          a_1*X_1 + a_2*X_2 + . . . + a_n*X_n = M

Input
Dòng 1: n và M
Dòng 2: a1, a2, ..., an
Output: Số nghiệm nguyên dương
Ví dụ
Input
3 5
1 1 1
Output
6
*/

#include<bits/stdc++.h>

using namespace std;

int n, m;
int totalSolution = 0;
vector<int> coeff;

int TRY(int index){
    if(index == n){
        if(m == 0) totalSolution++;
        return 1;
    }
    if(m < 0) return 1;
    for(int i = 1; i <= m; i++){
        m -= coeff[index]*i;
        TRY(index + 1);
        m += coeff[index]*i;
    }
    return 1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        coeff.push_back(temp);
    }

    for(int i = 1; i <= m; i++){
        m -= coeff[0]*i;
        TRY(1);
        m += coeff[0]*i;
    }

    cout << totalSolution;
}