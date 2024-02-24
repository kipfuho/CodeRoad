/*
Description
Given a sequence of integers a1, a2, ..., an. Sort the sequence in a non-deccreasing order.
Input
Line 1: contains an integer n (1 <= n <= 1000000)
Line 2: a1, a2, ..., an. (0 <= ai <= 100000)
Output
Write the sorted sequence, elements are separated by a SPACE chharacter.
Example
Input
4
1 3 4 2
Output
1 2 3 4
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int mod = 1e9 + 7;

int merge_sort(int arr[], int dummy[], int left, int right){
    if(left > right) return 0;
    long long count = 0; // for inversion problem
    if(left < right){
        int mid = (left + right) / 2;
        count += merge_sort(arr, dummy, left, mid);
        count += merge_sort(arr, dummy, mid+1, right);
        int start1 = left, start2 = mid + 1, index = left;
        while(start1 <= mid && start2 <= right){
            if(arr[start1] <= arr[start2]) dummy[index++] = arr[start1++];
            else{
                dummy[index++] = arr[start2++]; 
                count += (mid - start1 + 1);
            }
        }
        while(start1 <= mid){
            dummy[index++] = arr[start1++];
        }
        while(start2 <= right) dummy[index++] = arr[start2++]; 
        for(int i = left; i <= right; i++) arr[i] = dummy[i];
    }
    return count%mod;
}

int main(){_
    int n; cin >> n;
    int arr[n], dummy[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, dummy, 0, n - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}