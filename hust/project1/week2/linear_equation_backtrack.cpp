#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr(10);

auto PRINT(){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int TRY(int i){
    if(i == n && m == 0){
        PRINT();
        return 1;
    }
    for(int j = 1; j <= m; j++){
        if(m - j < 0) break;
        arr[i] = j;
        m -= j;
        TRY(i + 1);
        m += j;
    }

    return 1;
}

int main(){
    cin >> n >> m;

    TRY(0);
    
    return 1;
}