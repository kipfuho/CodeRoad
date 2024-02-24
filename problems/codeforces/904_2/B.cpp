// https://codeforces.com/contest/1884/problem/B

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, count = 0; cin >> n;
        queue<int> holes;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for(int i = 1; i < n; i++){
            if(s[i] == '0') holes.push(i);
            else count++;
        }
        if(s[0] == '1') count++;
        if(count == 0){
            for(int i = 1; i <= n; i++) cout << "0 ";
            cout << "\n";
            continue;
        }
        long long step = 0;
        int i;
        for(i = 0; i < n; i++){
            if(s[i] == '1'){
                if(!holes.empty()){
                    int top = holes.front();
                    holes.pop();
                    step += top - i;
                    swap(s[i], s[top]);
                }
                else{
                    cout << "-1 ";
                    break;
                }
            }
            else{
                if(!holes.empty()){
                    int top = holes.front();
                    if(top <= i) holes.pop();
                }
            }
            cout << step << " ";
        }
        for(++i; i < n; i++) cout << "-1 ";
        cout << endl;
    }
    return 0;
}