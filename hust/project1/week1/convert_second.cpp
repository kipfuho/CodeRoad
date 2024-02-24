/*
Description
Given a time moment which is a string under the format hh:mm:ss (in which hh (0 <= hh <= 23) is the hour, mm (0 <= mm <= 59) is the minute, and ss (0 <= ss <= 59) is the second). Convert this time moment in seconds (result = hh*3600 + mm*60 + ss).
Input
Line 1: contains a string s representing the time moment.  
Output
if s is not under the format hh:mm:ss, then write INCORRECT. Otherwise, write value converted.

Example
Input
13:05:26

Output
47126


Input
13:05:6

Output
INCORRECT 

Input
13:05 26

Output
INCORRECT
*/

#include <bits/stdc++.h> 

using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.size() != 8){
        cout << "INCORRECT";
        return 0;
    }
    if(s[2] != ':' || s[5] != ':'){
        cout << "INCORRECT";
        return 0;
    }
    int arr[6] = {s[0] - '0', s[1] - '0', s[3] - '0', s[4] - '0', s[6] - '0', s[7] - '0'};
    for(auto& x : arr){
        if(x > 9 || x < 0){
            cout << "INCORRECT";
            return 0;
        }
    }
    int hours = 10*arr[0] + arr[1], minutes = 10*arr[2] + arr[3], seconds = 10*arr[4] + arr[5];
    if(hours > 24 || minutes > 59 || seconds > 59){
        cout << "INCORRECT";
        return 0;
    }
    cout << hours*3600 + minutes*60 + seconds;
    return 0;
}