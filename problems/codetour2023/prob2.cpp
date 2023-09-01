#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n; cin >> n;
  int arr[n];
  int value[n];
  for(int i = 0; i < n; i++){
    arr[i] = i;
    value[i] = 1;
  }
  int t1, t2;
  while(cin >> t1 >> t2){
    while(arr[t1] != t1){
        t1 = arr[t1];
    }
    while(arr[t2] != t2){
        t2 = arr[t2];
    }
    if(t1 != t2){
      value[t1] += value[t2];
      value[t2] = 0;
      arr[t2] = t1;
    }
  }
  sort(value, value + n, greater<int>());
  int j = 0;
  while(value[j] > 0){
    j++;
  }
    long long res = 0;
  for(int i = 0; i < j - 1; i++){
    for(int k = i + 1; k < j; k++){
      res += value[i]*value[k];
    }
  }
  cout << res;
}