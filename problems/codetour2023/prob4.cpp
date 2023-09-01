#include<iostream>

using namespace std;

int m, n;

int main(){
  cin >> m >> n;
  int arr[m][n];
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
    }
  }
  int k = 0;
  string temp;
  while(cin >> temp){
    if(temp == "T") k--;
    if(temp == "2T") k-=2;
    if(temp == "3T") k-=3;
    if(temp == "P") k++;
    if(temp == "2P") k+=2;
    if(temp == "3P") k+=3;
  }
  k %= 4;
  if(k == 0){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if(k == 1 || k == -3){
        for(int i = 0; i < n; i++){
            for(int j = m - 1; j >= 0; j--){
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
    }
    else if(k == -1 || k == 3){
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
    }
    else{
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}