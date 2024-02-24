/*
Description
There are two jugs, a-litres jug and b-litres jug (a, b are positive integers). There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.
Input
   Line 1: contains positive integers a,   b,  c  (1 <= a, b, c <= 900)
Output
  write the number of steps or write -1 (if no solution found)
Example

Input
6  8  4
Output
4
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    queue<pair<pair<int, int>, int>> q;
    map<pair<int, int>, int> mp;
    int a, b, c; cin >> a >> b >> c;
    q.push({{a, 0}, 1});
    q.push({{0, b}, 1});

    pair<pair<int, int>, int> qFront;
    while(!q.empty()){
        qFront = q.front();
        q.pop();

        pair<int, int> state = qFront.first;
        int step = qFront.second;
        if(mp[state] == 1) continue;
        if(state.first < 0 || state.first > a || state.second < 0 || state.second > b) continue;
        
        mp[state] = 1;

        if(state.first == c || state.second == c){
            cout << step;
            return 1;
        }

        // empty jug a
        if(state.first > 0){
            q.push({{0, state.second}, step + 1});
        }
        // empty jug b
        if(state.second > 0){
            q.push({{state.first, 0}, step + 1});
        }
        // fill jug a and transfer from jug b to jug a
        if(state.first < a){
            q.push({{a, state.second}, step + 1});
            if(state.second > 0){
                int minAmount = min(state.second, a - state.first);
                q.push({{state.first + minAmount, state.second - minAmount}, step + 1});
            }
        }
        // fill jug b and transfer from jug a to jug b
        if(state.second < b){
            q.push({{state.first, b}, step + 1});
            if(state.first > 0){
                int minAmount = min(state.first, b - state.second);
                q.push({{state.first - minAmount, state.second + minAmount}, step + 1});
            }
        }
    }

    cout << -1;

    return 0;
}