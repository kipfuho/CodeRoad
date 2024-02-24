/*
Description
Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}. Given a positive integer m, the hash code of s is defined by the formula:
H(s) =  (s[1]*256
k-1
 + s[2]*256
k-2
 + . . . + s[k]*256
0 
) mod m  (the contant integer m is a parameter)
Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes
Input
Line 1: n and m (1 <= n,m <= 100000)
Line i+1 (i = 1,2,…,n): contains the string ki (the length of each string is less than or equal to 200)
Output
Each line contains the corresponding hash code of n given strings
Example
Input
4 1000
a
ab
abc
abcd
Output
97
930
179
924
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    string s;
    long long pow[200];
    pow[0] = 1;
    for(int i = 1; i <= 200; i++){
        pow[i] = pow[i-1]*256 % m;
    }
    for(int i = 0; i < n; i++){
        cin >> s;
        long long hash = 0;
        int k = s.size();
        for(int j = 0; j < k; j++){
            hash = (hash + pow[k - j - 1]*s[j]) % m;
        }
        cout << hash << "\n";
    }
    return 0;
}