// https://codeforces.com/contest/1881/problem/D

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> mark;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            int temp; cin >> temp;
            for(int j = 2; j <= sqrt(temp); j++){
                if(temp%j == 0){
                    int count = 0;
                    while(temp%j == 0){
                        temp /= j;
                        count++;
                    }
                    if(mp[j]){
                        mp[j] += count;
                    }
                    else{
                        mark.push_back(j);
                        mp[j] = count;
                    }
                }
            }
            if(temp > 1){
                if(mp[temp]){
                    mp[temp]++;
                }
                else{
                    mark.push_back(temp);
                    mp[temp] = 1;
                }
            }
        }

        bool check = true;
        for(auto& x:mark){
            if(mp[x]%n != 0){
                check = false;
                break;
            }
        }
        if(check){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}