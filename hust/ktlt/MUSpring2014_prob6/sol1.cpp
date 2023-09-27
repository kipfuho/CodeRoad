#include<iostream>
#include<vector>
#define ll long long

using namespace std;

int n;
vector<ll> a;

// return true if there's a subarray with avg <= x
bool check(double x){
    vector<double> minSumL(n), minSumR(n), offset;
    for(int i = 0; i < n; i++){
        offset.push_back((double)a[i] - x);
    }

    // set value for minSumL and minSumR
    double sum = offset[0];
    minSumL[0] = offset[0];
    for(int i = 1; i < n; i++){
        sum += offset[i];
        minSumL[i] = min(minSumL[i - 1], sum);
    }
    sum = offset[n - 1];
    minSumR[n - 1] = offset[n - 1];
    for(int i = n - 2; i >= 0; i--){
        sum += offset[i];
        minSumR[i] = min(minSumR[i + 1], sum);
    }

    for(int i = 0; i < n - 2; i++){
        if(minSumL[i] + minSumR[i + 2] < 1e-4){
            return true;
        }
    }
    return false;
}

double sol() {
    int n = a.size();
    double high = (a[0] + a[n - 1]) / 2.0;
    double low = 0, mid = 0;
    while(high - low > 1e-5){
        mid = (high + low) / 2.0;
        if(check(mid)){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return mid;
}

int main(int argc, char** argv) {
    freopen("input.inp", "r", stdin);
    freopen("sol1.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a.push_back(x);
    }

    printf("%.3lf", sol());

    return 0;
}
