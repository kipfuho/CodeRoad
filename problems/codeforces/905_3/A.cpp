// https://codeforces.com/contest/1883/problem/A

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string code; cin >> code;
        if(code[0] == '0') code[0] = ':';
        if(code[1] == '0') code[1] = ':';
        if(code[2] == '0') code[2] = ':';
        if(code[3] == '0') code[3] = ':';
        int time = code[0] - '0' + abs(code[1] - code[0]) + abs(code[2] - code[1]) + abs(code[3] - code[2]) + 3;
        cout << time << endl;
    }
    return 0;
}