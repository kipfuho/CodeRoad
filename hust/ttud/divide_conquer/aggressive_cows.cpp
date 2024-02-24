/*
E. 04. AGGRCOW
time limit per test4.0 s
memory limit per test 256 megabytes
inputstandard input
outputstandard output

Farmer John has built a new long barn, with N (2≤N≤100,000) stalls. The stalls are located along 
a straight line at positions x1,…,xN (0≤xi≤1,000,000,000). His C (2≤C≤N) cows don't like this barn 
layout and become aggressive towards each other once put into a stall. To prevent the cows from 
hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between 
any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows.
Line 1: Two space-separated integers: N and C
Lines 2…N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.

Example
input
1
5 3
1
2
8
4
9
output
3
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int left = 1, mid, right = arr[n-1], last, count, best = 1;
        while(left <= right){
            mid = (left + right)/2;
            last = arr[0];
            count = 1;
            for(int i = 1; i < n; i++){
                if(arr[i] - last >= mid){
                    count++;
                    last = arr[i];
                }
            }
            if(count < c){
                right = mid - 1;
            }
            else{
                best = mid;
                left = mid + 1;
            }
        }
        cout << best << endl;
    }
    return 0;
}