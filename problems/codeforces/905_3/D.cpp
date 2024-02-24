// https://codeforces.com/contest/1883/problem/D

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    multiset<int> mp_left, mp_right;
    bool valid = false;
    while(q--){
        char op;
        int l, r;
        cin >> op >> l >> r;
        if(op == '+'){
            mp_right.insert(l);
            mp_left.insert(r);
            if(valid) cout << "YES\n";
            else{
                int right = *mp_left.begin(), left = *(--mp_right.end());
                if(left > right){
                    cout << "YES\n";
                    valid = true;
                }
                if(!valid) cout << "NO\n";
            }
        }
        else{
            mp_right.erase(mp_right.find(l));
            mp_left.erase(mp_left.find(r));
            valid = false;
            if(mp_left.size()){
                int right = *mp_left.begin(), left = *(--mp_right.end());
                if(left > right){
                    cout << "YES\n";
                    valid = true;
                }
            }
            if(!valid) cout << "NO\n";
        }
    }
    return 0;
}