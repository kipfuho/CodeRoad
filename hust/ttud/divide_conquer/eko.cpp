/*
C. 04. EKO
time limit per test 1 second
memory limit per test 256 megabytes
input standard input
output standard output

Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting 
machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko's machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade 
to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko 
then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 
metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 
metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

Mirko is ecologically minded, so he doesn't want to cut off more wood than necessary. That's why he wants to set his sawblade 
as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M 
metres of wood.

Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1≤N≤1000000) 
and M (Mirko's required wood amount, 1≤M≤2000000000).

The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights 
of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the 
required amount of wood.

Output
The first and only line of output must contain the required height setting.

Examples
input
4 7
20 15 10 17
output
15

input
5 20
4 42 40 26 46
output
36
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int n, m; cin >> n >> m;
    int left = INT_MAX, mid, right = INT_MIN, temp, best;
    long long curr_sum;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        left = min(left, arr[i]);
        right = max(right, arr[i]);
    }
    while(left <= right){
        mid = (left + right) / 2;
        curr_sum = 0;
        for(int i = 0; i < n ; i++){
            temp = arr[i] - mid;
            if(temp > 0) curr_sum += temp;
        }
        if(curr_sum < m){
            right = mid - 1;
        }else{
            best = mid;
            left = mid + 1;
        }
    }
    cout << best;
    return 0;
}