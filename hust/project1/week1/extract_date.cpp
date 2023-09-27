/*
Description
Given a date which is a string under the format YYYY-MM-DD (in which YYYY is the year, MM is the month (the month í from 1 to 12), and DD is the date (the date is from 1 to 31)). Extract the year, month and date.
Input
Line 1: contains a string s  
Output
if s is not under the format YYYY-MM-DD, then write INCORRECT. Otherwise, write year, month, and date separated by a SPACE character

Example
Input
2023-10-04
Output
2023 10 4


Input
2023-10-4
Output
INCORRECT 

Input
2023-10 04
Output
INCORRECT
*/

#include <bits/stdc++.h> 

using namespace std;

int main() 
{
    string s;
    cin >> s;
    if(s.size() != 10){
        cout << "INCORRECT";
        return 0;
    }
    if(s[4] != '-' || s[7] != '-'){
        cout << "INCORRECT";
        return 0;
    }
    int arr[8] = {s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0', s[5] - '0', s[6] - '0', s[8] - '0', s[9] - '0'};
    for(auto& x : arr){
        if(x > 9 || x < 0){
            cout << "INCORRECT";
            return 0;
        }
    }
    int year = 1000*arr[0] + 100*arr[1] + 10*arr[2] + arr[3], month = 10*arr[4] + arr[5], day = 10*arr[6] + arr[7];
    if(month > 12 || day > 31){
        cout << "INCORRECT";
        return 0;
    }
    cout << year << " " << month << " " << day;
}