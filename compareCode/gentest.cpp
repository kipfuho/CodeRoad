#include <bits/stdc++.h>
using namespace std;

long long random(long long L, long long H){
    return (rand()<<16|rand()) % (H-L+1) + L;
}

void gentest(){
        int n = random(1, 10), l1 = random(1, n), l2 = random(l1, n);
        cout << n << " " << l1 << " " << l2 << endl;
        for(int i = 0; i < n; i++){
            long long x = random(0, 10000);
            cout << x << " ";
        }
        cout << endl;
}


vector<int> testarray(5, 0);
void gentest1(int n, int c){
    for(int i = 0; i <= n; i++){
        testarray[n - 1] = i;
        cout << n << " " << c << endl;
        for(int j = 0; j < n; j++) cout << testarray[j] << " ";
        cout << endl;
        if(n < 5) gentest1(n + 1, c);
    }
}

int main(int argc, char** argv){
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
    freopen("input.inp", "w", stdout);
    gentest();
}
