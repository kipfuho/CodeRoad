// https://codeforces.com/contest/1891/problem/C

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

int arr[200001];

int main(){_
    int t; cin >> t;
    while(t--){
        int n, temp; cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr + 1, arr + n + 1);
        ll left = 1, right = n, suml = 0, count = 0;
        while(left < right){
            if(suml + arr[left] <= arr[right]){
                suml += arr[left];
                left++;
            }
            else{
                temp = arr[right] - suml;
                count += (suml + temp + 1);
                suml = 0;
                while(arr[left] < temp && left < right){
                    temp -= arr[left];
                    left++;
                }
                arr[left] -= temp;
                right--;
            }
        }
        count += suml;
        arr[right] += suml;
        if(arr[right] > 1) count += (arr[right]/2 - suml + 1);
        count += arr[right]%2;
        cout << count << endl;
    }
    return 0;
}