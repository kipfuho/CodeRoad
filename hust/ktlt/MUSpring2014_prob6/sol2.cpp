#include<iostream>
#include<vector>
#define ll long long

using namespace std;

double sol(const vector<ll>& a) {
    int n = a.size();
    ll amax = -1;
    vector<ll> prefixsum(n);
    prefixsum[0] = a[0];
    for(int i = 1; i < n - 1; i++){
        prefixsum[i] = prefixsum[i - 1] + a[i];
        if(amax < a[i]) amax = a[i];
    }
    prefixsum[n - 1] = prefixsum[n - 2] + a[n - 1];

    int len = n;
    ll sum = prefixsum[n - 1];
    double minAver = (double)sum / n;

    for(int i = 1; i < n - 1; i++){
        for(int j = i; j < n - 1; j++){
            int w = n - j + i - 1;
            double aver = (double)(sum - (prefixsum[j] - prefixsum[i - 1]))/w;
            if(aver < minAver){
                minAver = aver;
                len = w;
            }
        }
    }
    if(len == n){
        return (double)(sum - amax) / (n - 1);
    }
    else return minAver;
}

int main(int argc, char** argv) {
    freopen("input.inp", "r", stdin);
    freopen("sol2.out", "w", stdout);
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    printf("%.3lf", sol(a));

    return 0;
}
