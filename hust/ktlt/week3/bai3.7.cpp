// Nguyen Dinh Ut Biu 20215317
// Bai3.7: Su dung phuong pháp khu de quy bang stack, hãy liet kê các xâu nhi phân do dài n không có k bit 1 nào liên tiep.

#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        
        //# Khu de quy
        // if current bit is 1, set L to old L to compare with k later
        if (top.j > 0){
            L = top.old_L;
        }
        // already tried 2 state of a bit -> pop from stack
        if (top.j > 1){
            s.pop();
            continue;
        }
        
        // if current bit is 1 we have to check if L + 1 (L calculated from above) is smaller than k
        // else we can ignore because we already know L < k
        if(L + 1 < k || top.j == 0){
        	// set x and old_L
            x[top.i] = top.j;
            top.old_L = L;
            if(top.j){
                L++;
            }
            else{
                L = 0;
            }
            s.push(state(top.i + 1, 0));
        }
        top.j++;
    }
    return 0;
}
