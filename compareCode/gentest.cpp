#include <bits/stdc++.h>
using namespace std;

int random(int L, int H){
    return (rand()<<16|rand()) % (H-L+1) + L;
}

void gentest(){
    int n = random(1, 1e4), m = random(1, 1e4);
    cout << n << " " << m << endl;
    char s[2] = {'+', '-'};
    for(int i = 0; i < n; i++){
        int t = random(0, 1);
        cout << s[t];
    }
    cout << endl;
    for(int i = 0; i < m; i++){
        int l = random(1, n), r = random(l, n);
        cout << l << " " << r << endl;
    }
}

int main(int argc, char** argv){
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
    freopen("input.inp", "w", stdout);
    gentest();
}
