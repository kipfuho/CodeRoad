#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        int left = 1, mid, right = arr[n-1], last, count, best = 1;
        while(left <= right){
            mid = (left + right)/2;
            last = arr[0];
            count = 1;
            for(int i = 1; i < n; i++){
                if(arr[i] - last >= mid){
                    count++;
                    last = arr[i];
                }
            }
            if(count < c){
                right = mid - 1;
            }
            else{
                best = mid;
                left = mid + 1;
            }
        }
        cout << best << endl;
    }
    return 0;
}