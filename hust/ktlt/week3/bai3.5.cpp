// Nguyen Dinh Ut Biu 20215317
// Bai3.5: Tính he so to hop C(n, k)

#include <iostream>
#include <math.h>
using namespace std;

// Tinh bang de quy
int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

// Tinh bang cach khu de quy
int binom2(int n, int k){
    if(k == 0 || k == n) return 1;
    long res = 1;
    for(int i = 1; i <= n - k; i++){
        res *= (double) k/i + 1;
    }
    return round(res);
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
