/*
Description
Given a TEXT, write a program that converts the TEXT to upper-case. 

Input
The TEXT

Output
The TEXT in which characters are converted into upper-case

Example 
Input 
Hello John,
How are you?

Bye,

Output 
HELLO JOHN,
HOW ARE YOU?

BYE, 
*/

#include <bits/stdc++.h> 

using namespace std;

int main() 
{
    string s;
    while(getline(cin, s)){
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] -= 32;
            }
        }
        cout << s << endl;
    }
}