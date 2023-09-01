#include<iostream>
#define ll long long

using namespace std;

int main(){
    int n; ll x;
    cin >> n >> x;
    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll delta[n], prefixsum[n];
    delta[0] = prefixsum[0] = 0;
    for(int i = 1; i < n; i++){
        delta[i] = abs(arr[i] - arr[i - 1]);
        prefixsum[i] = prefixsum[i - 1] + delta[i];
    }
    int dp[n], left;
    if(delta[1] > x){
        dp[1] = 1;
        left = 1;
    }
    else{
        dp[1] = 0;
        left = 0;
    }
    int res = dp[1];
    for(int i = 2; i < n; i++){
        int offset = 0;
        for(;left < i;){
            if((prefixsum[i] - prefixsum[left])*(i - left) >= x){
                offset++;
                left++;
            }
            else{
                break;
            }
        }
        dp[i] = dp[i - 1] + offset;
        res += dp[i];
    }
    cout << endl << res;
}