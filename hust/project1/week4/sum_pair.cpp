/*
Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, temp; cin >> n >> m;
    vector<int> arr;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(mp[temp]) mp[temp]++;
        else{
            mp[temp] = 1;
        }
        arr.push_back(temp);
    }

    int res = 0;
    for(auto& x:arr){
        if(m&1){
            res += mp[m-x];
        }
        else{
            if(x == m/2){
                res += (mp[m-x] - 1);
            }
            else{
                res += mp[m-x];
            }
        }
        mp[x] = 0;
    }

    cout << res;

    return 0;
}