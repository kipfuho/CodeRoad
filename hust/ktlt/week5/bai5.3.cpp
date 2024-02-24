// Nguyễn Đình Út Biu 20215317
// Bài tập 3: Dãy ngoặc đúng

#include <iostream>
using namespace std;
#include <string.h>
#include <stack>

int par(string str){
    int a = str.length();
    stack<char> S;
    char x; // y không dùng bỏ y
    for (int i=0; i<a; i++){
        x = str[i];
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        else {
            if(S.empty()){ // Nếu stack empty thì không cần kiểm tra nữa
                return 0;
            }
            if (x == ')') {
                if (S.top() == '('){
                    S.pop();
                }
                else return 0;
            }
            else if (x == ']') {
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') { // Phần else if này sai ngoặc {}
                if (S.top() == '{'){
                    S.pop();
                }
            }
            else return 0;
        }
    }
    if (!S.empty()){ // Sửa lại điều kiện
        return 0;
    }
    else return 1;
}

int main(){
    int n;
    string str;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        cout << par(str) << endl;
    }

    return 0;
}
