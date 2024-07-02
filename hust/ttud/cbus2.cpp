/*
Description
There are n passengers 1, 2, …, n. The passenger i want to travel from point i to 
point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for 
transporting the passengers (it means at any time, there are at most k passengers 
on the bus). You are given the distance matrix c in which c(i,j) is the traveling 
distance from point i to point j (i, j = 0,1,…, 2n). Moreover, maximum distance a
passenger take must be smaller than D. Compute the shortest route for 
the bus, serving n passengers and coming back to point 0. 
Input
Line 1 contains n and k (1≤n≤11,1≤k≤10)
 Line i+1 (i=1,2,…,2n+1) contains the (i−1)
th
 line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
Output
Unique line contains the length of the shortest route.
Example
Input
3  2 15
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25
*/

#include<bits/stdc++.h>

using namespace std;

int n, k, D;
int best = INT_MAX;
int minWeight = INT_MAX;
int curWeight = 0;
int curPassenger = 0;
int leftPassenger;
vector<vector<int>> c(23, vector<int>(23));
vector<int> visited(23);
vector<int> pickedPassenger(12, 0);
vector<int> d(12, 0);

void changeD(int val, bool revert = false) {
    if(revert) {
        for(int j = 1; j <= n; j++) {
            if(pickedPassenger[j] == 1) {
                d[j] -= val;
            }
        }
    }
    else {
        for(int j = 1; j <= n; j++) {
            if(pickedPassenger[j] == 1) {
                d[j] += val;
            }
        }
    }
    return;
}

inline int TRY(int count, int prev, int now){
    //cout << count << " " << prev << " " << now << " " << curWeight << endl;
    //visited[now] = prev;
    for(int j = 1; j <= n; j++) {
        if(pickedPassenger[j] == 1 && (d[j] + c[prev][now] >= D)) return 0;
    }
    if(curWeight + minWeight*(2*n + 1 - count) > best) return 1;
    changeD(c[prev][now]);
    if(now <= n){
        pickedPassenger[now] = 1;
        curPassenger++;

        for(int i = 1; i <= n; i++){
            if(pickedPassenger[i] == 0 && curPassenger < k){
                
                curWeight += c[now][i];
                TRY(count + 1, now, i);
                curWeight -= c[now][i];
            }
            
            if(pickedPassenger[i] == 1){
                curWeight += c[now][i + n];
                TRY(count + 1, now, i + n);
                curWeight -= c[now][i + n];
            }
        }

        pickedPassenger[now] = 0;
        curPassenger--;
    }
    else{
        pickedPassenger[now - n] = 2;
        leftPassenger--;
        curPassenger--;

        if(leftPassenger == 0){
            curWeight += c[now][0];
            
            /*
            cout << curWeight << endl;
            int u = now;
            while(u != 0){
                cout << u << " ";
                u = visited[u];
            }
            cout << endl;
            */

            if(curWeight < best){
                best = curWeight;
            }
            curWeight -= c[now][0];
            pickedPassenger[now - n] = 1;
            leftPassenger++;
            curPassenger++;
            changeD(c[prev][now], true);
            return 1;
        }

        for(int i = 1; i <= n; i++){
            if(pickedPassenger[i] == 0){
                curWeight += c[now][i];
                TRY(count + 1, now, i);
                curWeight -= c[now][i];
            }
            
            if(pickedPassenger[i] == 1){
                curWeight += c[now][i + n];
                TRY(count + 1, now, i + n);
                curWeight -= c[now][i + n];
            }
        }
        
        pickedPassenger[now - n] = 1;
        leftPassenger++;
        curPassenger++;
    }
    changeD(c[prev][now], true);
    return 1;
}

int main(){
    cin >> n >> k >> D;
    for(int i = 0; i < 2*n + 1; i++){
        for(int j = 0; j < 2*n + 1; j++){
            cin >> c[i][j];
            if(i != j){
                minWeight = min(minWeight, c[i][j]);
            }
        }
    }

    leftPassenger = n;
    for(int i = 1; i <= n; i++){
        curWeight += c[0][i];
        //visited[i] = 0;
        TRY(0, 0, i);
        curWeight -= c[0][i];
    }
    cout << best;
}