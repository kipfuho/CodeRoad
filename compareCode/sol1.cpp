#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

// put sol1 here
void sol(){
    int n, m; cin >> n >> m;
    vector<int> maxl(n + 2), minl(n + 2), maxr(n + 2), minr(n + 2);
    string s; cin >> s;

    maxl[n + 1] = minl[n + 1] = 0;
    maxl[0] = minl[0] = 0;
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '+'){
            sum1++;
            sum2 = 0;
        }
        else{
            sum1 = 0;
            sum2--;
        }
        maxl[i] = max(maxl[i - 1] - 1, sum1);
        minl[i] = min(minl[i - 1] + 1, sum2);
    }
    maxr[n + 1] = minr[n + 1] = 0;
    maxr[0] = minr[0] = 0;
    sum1 = 0, sum2 = 0;
    for(int i = n; i > 0; i--){
        if(s[i - 1] == '+'){
            sum1++;
            sum2 = 0;
        }
        else{
            sum1 = 0;
            sum2--;
        }
        maxr[i] = max(maxr[i + 1] - 1, sum1);
        minr[i] = min(minr[i + 1] + 1, sum2);
    }

    while(m--){
        int l, r; cin >> l >> r;
        int best = max(maxr[r + 1] + maxl[l - 1], -(minr[r + 1] + minl[l - 1]));
        cout << best + 1 << endl;
    }
}

void sol1(){
    int n, m;
    cin >> n >> m;
    cout << m << n;
}

int main(int argc, char** argv) {
    freopen("input.inp", "r", stdin);
    freopen("sol1.out", "w", stdout);
    sol();
}