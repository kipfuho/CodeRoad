#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    --n;
    double fibn = pow(1.0/2.0+sqrt(5)/2.0, n)/sqrt(5) - pow(1.0/2.0-sqrt(5)/2.0, n)/sqrt(5);
    cout << fibn;
}