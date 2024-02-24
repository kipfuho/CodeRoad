/*
ProblemE.FibonacciWords
InputFileName: stdin
OutputFileName: stdout
TimeLimit: 1s
MemoryLimit: 256MB

The Fibonacci word sequence of bit strings is defined as:
F(n) =  /   0                   if n = 0
        \   1                   if n = 1
         \  F(n-1) + F(n-2)     if n >= 2

Here denotes concatenation of strings.The first few elements are:
n   F(n)
0   0
1   1
2   10
3   101
4   10110
5   10110101
6   1011010110110
7   101101011011010110101
8   1011010110110101101011011010110110
9   1011010110110101101011011010110110101101011011010110101

Given a bit pattern p and a number n,how often does p occur in F(n)?

Input
The first line of each test case contains the integern(0 <= n <= 100). The second line contains the bit
pattern p.The pattern p is nonempty and has a length of at most 100 000 characters.
Output
For each test case, display its case number followed by the number of occurrences of the bit pattern p in
F(n). Occurrences may overlap. The number of occurrences will be less than 2^63.

Example:
input:
6
10
output:
Case 1: 5
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
string pattern;
vector<long long> fibo(101, 0), overlap(101, 0);
vector<string> fw(101); // store fibonacci word

long long count_appear_kmp(string text, string pattern){
    int text_size = text.size(), pattern_size = pattern.size();
    // calculate lps - longest prefix suffix
    int lps[pattern_size], i = 1, j = 0;
    lps[0] = 0;
    while(i < pattern_size){
        if(pattern[i] == pattern[j]) lps[i++] = ++j;
        else{
            if(j != 0) j = lps[j - 1];
            else lps[i++] = 0;
        }
    }
    // for(i = 0; i < m; i++) cout << lps[i] << " ";

    // count time pattern appear in text
    long long count = 0;
    i = 0; j = 0;
    while((text_size - i) >= (pattern_size - j)){
        if(pattern[j] == text[i]){
            j++;
            i++;
            if (j == pattern_size){
                count++;
                j = lps[j - 1];
            }
        }
        else{
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return count;
}

int create_fw(string pattern){
    int p_size = pattern.size();
    // cout << p_size << endl;
    // trivial case for small p :D
    if(p_size == 1){
        overlap[0] = 0;
        overlap[1] = 0;
        fibo[0] = 0;
        fibo[1] = 0;
        if(pattern == "1") fibo[1] = 1;
        else if(pattern == "0") fibo[0] = 1;
        return 2;
    }
    if(p_size == 2){
        overlap[0] = 0;
        overlap[1] = count_appear_kmp("11", pattern);
        overlap[2] = count_appear_kmp("01", pattern);
        overlap[3] = overlap[1];
        fibo[2] = count_appear_kmp("10", pattern);
        fibo[3] = count_appear_kmp("101", pattern);
        return 4;
    }
    // common case 
    // find first fw that is equal or bigger than pattern / 2
    fibo[0] = 1; fibo[1] = 1;
    fw[0] = "0"; fw[1] = "1";
    int i;
    for(i = 2; i <= n; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fw[i] = fw[i - 1] + fw[i - 2];
        if(2*fibo[i] >= p_size) break;
    }
    
    // create 2 more fw fw(i + 1) and fw(i + 2), from fw(i + 3) it has the same pattern to count toward result
    fw[i + 1] = fw[i] + fw[i - 1];
    fibo[i + 1] = fibo[i] + fibo[i - 1];
    if(fibo[i + 1] <= p_size){
        fw[i + 2] = fw[i + 1] + fw[i];
        fw[i + 3] = fw[i + 2] + fw[i + 1];
        fibo[i + 1] = count_appear_kmp(fw[i + 1], pattern);
        fibo[i + 2] = count_appear_kmp(fw[i + 2], pattern);
        fibo[i + 3] = count_appear_kmp(fw[i + 3], pattern);
        overlap[i] = count_appear_kmp(fw[i] + fw[i], pattern);
        overlap[i + 1] = count_appear_kmp(fw[i + 1] + fw[i + 1], pattern) - 2*fibo[i + 1];
        if(overlap[i] != 0) overlap[i + 2] = overlap[i];
        else overlap[i + 2] = count_appear_kmp(fw[i + 2] + fw[i + 2], pattern) - 2*fibo[i + 2];
        if(overlap[i + 1] != 0) overlap[i + 3] = overlap[i + 1];
        else overlap[i + 3] = count_appear_kmp(fw[i + 3] + fw[i + 3], pattern) - 2*fibo[i + 3];
        return i + 4;
    }
    else{
        fw[i + 2] = fw[i + 1] + fw[i];
        fibo[i + 1] = count_appear_kmp(fw[i + 1], pattern);
        fibo[i + 2] = count_appear_kmp(fw[i + 2], pattern);
        overlap[i] = count_appear_kmp(fw[i] + fw[i], pattern);
        overlap[i + 1] = count_appear_kmp(fw[i + 1] + fw[i + 1], pattern) - 2*fibo[i + 1];
        if(overlap[i] != 0) overlap[i + 2] = overlap[i];
        else overlap[i + 2] = count_appear_kmp(fw[i + 2] + fw[i + 2], pattern) - 2*fibo[i + 2];
        return i + 3;
    }
    
    return 0;
}

long long calculate_total_occurences(int start, int p_size){
    // trivial case p = "0" or p = "1"
    if(p_size == 1){
        fibo[start] = fibo[start - 1] + fibo[start - 2];
        start++;
    }
    for(int i = start; i <= n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2] + overlap[i-3];
        overlap[i] = overlap[i-2];
    }
    return fibo[n];
}

bool check_size(int p_size){
    if(p_size == 1) return true;
    int a1 = 1, a2 = 1, a3;
    for(int i = 2; i <= n; i++){
        a3 = a1 + a2;
        if(a3 >= p_size) return true;
        swap(a1, a2);
        swap(a2, a3);
    }
    return false;
}

int main(){
    int case_number = 1;
    while(cin >> n){
        cin >> pattern;
        if(check_size(pattern.size())){
            int start = create_fw(pattern);
            cout << "Case " << case_number << ": " << calculate_total_occurences(start, pattern.size()) << endl;
        }
        else{
            cout << "Case " << case_number << ": 0" << endl;
        }
        case_number++;
    }
    
    //for(int i = 0; i <= n; i++) cout << fibo[i] << " ";
    //cout << endl;
    //for(int i = 0; i <= n; i++) cout << overlap[i] << " ";
    return 0;
}