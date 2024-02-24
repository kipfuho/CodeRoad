/*
Description
Given a string containing only characters (, ), [, ] {, }. Write a program that checks whether the string is correct in expression.
Example
 ([]{()}()[]): correct
 ([]{()]()[]): incorrect
Input
One line contains the string (the length of the string is less than or equal to $10^6$)One line contains the string (the length of the string is less than or equal to 10
6
)
Output
Write 1 if the sequence is correct, and write 0, otherwise
Example
Input
(()[][]{}){}{}[][]({[]()})
Output
1
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<char> st;
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == '{' || c == '[' || c == '(') st.push(c);
        else{
            if(c == '}'){
                if(st.empty() || st.top() != '{'){
                    cout << 0;
                    return 1;
                }
                st.pop();
            }
            else if(c == ']'){
                if(st.empty() || st.top() != '['){
                    cout << 0;
                    return 1;
                }
                st.pop();
            }
            else if(c == ')'){
                if(st.empty() || st.top() != '('){
                    cout << 0;
                    return 1;
                }
                st.pop();
            }
            else{
                cout << 0;
                return 1;
            }
        }
    }
    if(st.empty()) cout << 1;
    else cout << 0;
    return 1;
}