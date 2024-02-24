// https://codeforces.com/contest/1883/problem/E

#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int save[100001];
    while(t--){
        int n, temp; cin >> n; cin >> temp;
        int last = temp;
        long long total = 0;
        save[0] = 0;
        for(int i = 1; i < n; i++){
            cin >> temp;
            int time = 0, multiplier = 1;
            while(last > temp*multiplier){
                multiplier = multiplier + multiplier;
                time++;
            }
            if(temp > last){
                multiplier = 1;
                while(temp >= last*multiplier){
                    multiplier = multiplier + multiplier;
                    time++;
                }
                save[i] = max(0, save[i-1] - time + 1);
            }
            else{
                save[i] = save[i-1] + time;
            }
            total += save[i];
            last = temp;
        }
        cout << total << endl;
    }
    return 0;
}