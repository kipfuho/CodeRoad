#include<bits/stdc++.h>
using namespace std;

long long count_appear_kmp(string text, string pattern){
    int n = text.size(), m = pattern.size();
    // calculate lps - longest prefix suffix
    int lps[m], i = 1, j = 0;
    lps[0] = 0;
    while(i < m){
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
    while((n - i) >= (m - j)){
        if(pattern[j] == text[i]){
            j++;
            i++;
            if (j == m){
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << count_appear_kmp("1011010110110101101011011010110110101101011011010110101", "1011");
}