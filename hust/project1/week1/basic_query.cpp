/*
Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
find-max: return the maximum element of the given sequence
find-min: return the minimum element of the given sequence 
sum: return the sum of the elements of the given sequence 
find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

Input
The first block contains the information about the given sequence with the following format:
Line 1: contains a positive integer n (1 <= n <= 10000)
Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
The first block is terminated by a character *
The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

Output
Write the result of each query in a corresponding line
 
Example
Input
5
1 4 3 2 5
*
find-max
find-min
find-max-segment 1 3
find-max-segment 2 5
sum
***

Output
5
1
4
5
15
*/

#include <bits/stdc++.h> 

using namespace std;

int main() 
{ 
    int n; cin >> n;
    vector<int> arr, tree(2e4);
    int maxArr = -1000, minArr = 1000, sum = 0;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        if(temp > maxArr) maxArr = temp;
        if(temp < minArr) minArr = temp;
        sum += temp;
        arr.push_back(temp);
    }

    for(int i = 0; i < n; i++){
        tree[n + i] = arr[i];
    }
    for(int i = n - 1; i > 0; i--){
        tree[i] = max(tree[i<<1], tree[i<<1 | 1]);
    }

    auto rmq = [&](int left, int right){
        left += n;
        right += n;
        int qResult = max(tree[left], tree[right - 1]);
        
        for(; left < right; left >>= 1, right >>= 1){
            if(left & 1){
                qResult = max(qResult, tree[left++]);
            }
            if(right & 1){
                qResult = max(qResult, tree[--right]);
            }
        }
        return qResult;
    };

    string s; cin >> s;
    while(1){
        cin >> s;
        if(s == "***") break;
        if(s == "find-max") cout << maxArr << endl;
        else if(s == "find-min") cout << minArr << endl;
        else if(s == "sum") cout << sum << endl;
        else if(s == "find-max-segment"){
            int i, j; cin >> i >> j;
            cout << rmq(i - 1, j) << endl;
        }
        else{
            continue;
        }
    }
    return 0;
}