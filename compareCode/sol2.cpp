#include<iostream>
#include<vector>
#define ll long long

using namespace std;

void sol2(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    while(m--){
        int l, r; cin >> l >> r;
        int max = 0, sum = 0;
        for(int i = 0; i < l - 1; i++){ 
            if(s[i] == '+') sum++;
            else sum--;
            if(abs(sum) > max) max = abs(sum);
        }
        for(int i = r; i < n; i++){
            if(s[i] == '+') sum++;
            else sum--;
            if(abs(sum) > max) max = abs(sum);
        }
        cout << abs(max) + 1 << endl;
    }
}

int main(int argc, char** argv) {
    freopen("input.inp", "r", stdin);
    freopen("sol2.out", "w", stdout);
    sol2();
}