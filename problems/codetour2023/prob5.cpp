#include<iostream>
#include<vector>
using namespace std;

vector<int> prefix, minprefix, maxprefix;

int main(){
  int n, m;
  cin >> n >> m;
  prefix.push_back(0);
  minprefix.push_back(0);
  maxprefix.push_back(0);

  for(int i = 0; i < n; i++){
    char temp; cin >> temp;
    if(temp == '+'){
      prefix.push_back(prefix.back() + 1);
    }
    else{
      prefix.push_back(prefix.back() - 1);
    }
    minprefix.push_back(min(prefix.back(), minprefix.back()));
    maxprefix.push_back(max(prefix.back(), maxprefix.back()));
  }

  while(m--){
    int l, r;
    cin >> l >> r;
    int offset = prefix[r] - prefix[l - 1];
    int maxvalue = maxprefix[r + 1] - offset;
    int minvalue = minprefix[r + 1] - offset;
    if(-minvalue > maxvalue){
      cout << -minvalue;
    }
    else{
      cout << maxvalue;
    }
  }
}