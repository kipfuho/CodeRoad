#include <bits/stdc++.h>
using namespace std;

int random(int L, int H){
    return (rand()<<16|rand()) % (H-L+1) + L;
}

int main(int argc, char** argv){
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
    freopen("input.inp", "w", stdout);
    int n = random(3, 10000);
    cout << n << endl;

    int amax = 1e8;
    for (int i = 0; i < n; ++i) {
        cout << random(0, amax) << " ";
    }
}
