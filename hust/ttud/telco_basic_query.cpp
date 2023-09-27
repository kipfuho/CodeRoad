/*
Problem: Telco Data Check & Analyze
Description
Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
The first block of data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under the form: 
        call <from_number> <to_number> <date> <from_time> <end_time> 
which is a call from the phone number <from_number> to a phone number <to_number> on <date>, and starting at time-point <from_time>, terminating at time-point <end_time>
<from_number> and <to_number> are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, the phone number is incorrect)
<date> is under the form YYYY-MM-DD (for example 2022-10-21)
<from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)
 
The second block consists of queries (terminated by a line containing #), each query in a line (number of lines can be up to 100000) and belongs to one of the following types:
?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
?number_total_calls: print to stdout (in a new line) the total number of calls of the data
?count_time_calls_from <phone_number>: print to stdout (in a new line) the total time duration (in seconds) the calls are made from <phone_number>
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int checkPhoneNumber = 1;
unordered_map<string, pair<int, int>> callMap;
int totalTimeCall = 0;

inline int calculateTime(string start, string end){
    return (end[0] - start[0])*36000 + (end[1] - start[1])*3600 + (end[3] - start[3])*600 + (end[4] - start[4])*60 + (end[6] - start[6])*10 + end[7] - start[7];
}

inline void checkPhone(string number){
    if(checkPhoneNumber){
        for(auto& x:number){
            if(x>'9' || x<'0') checkPhoneNumber = 0;
        }
    }
}

int main(){
    while(1){
        vector<string> block;
        string s; cin >> s;
        if(s == "#") break;
        for(int i = 0; i < 5; i++){
            cin >> s;
            block.push_back(s);
        }
        checkPhone(block[0]);
        //checkPhone(block[1]);
        callMap[block[0]].first++;
        callMap[block[0]].second += calculateTime(block[3], block[4]);
        totalTimeCall++;
    }
    while(1){
        string s; cin >> s;
        if(s == "#") break;
        if(s == "?check_phone_number"){
            cout << checkPhoneNumber << endl;
        }
        else if(s == "?number_calls_from"){
            string number; cin >> number;
            cout << callMap[number].first << endl;
        }
        else if(s == "?number_total_calls"){
            cout << totalTimeCall << endl;
        }
        else if(s == "?count_time_calls_from"){
            string number; cin >> number;
            cout << callMap[number].second << endl;
        }
        else{
            continue;
        }
    }
}