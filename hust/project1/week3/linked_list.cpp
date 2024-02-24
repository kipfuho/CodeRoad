/*
Description
Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a
1
, a
2
, …, a
n
, sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách

Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a
1
, a
2
, …, a
n
.
Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)
Output
Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho

Example
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#

Output
5 4 3 2 10 
*/

#include<bits/stdc++.h>

using namespace std;

int main(){
    list<int> list;
    map<int, int> mp;
    int n; cin >> n;
    while(n--){
        int temp; cin >> temp;
        list.push_back(temp);
        mp[temp] = 1;
    }
    string s;
    while(cin >> s){
        if(s == "#") break;
        else if(s == "addlast"){
            int temp; cin >> temp;
            if(mp[temp] == 0){
                mp[temp] = 1; 
                list.push_back(temp);
            }
        }
        else if(s == "addfirst"){
            int temp; cin >> temp;
            if(mp[temp] == 0){
                mp[temp] = 1; 
                list.push_front(temp);
            }
        }
        else if(s == "addafter"){
            int temp1, temp2; cin >> temp1 >> temp2;
            if(mp[temp2] == 1 && mp[temp1] == 0){
                mp[temp1] = 1;
                list.insert(++find(list.begin(), list.end(), temp2), temp1);
            }
        }
        else if(s == "addbefore"){
            int temp1, temp2; cin >> temp1 >> temp2;
            if(mp[temp2] == 1 && mp[temp1] == 0){
                mp[temp1] = 1;
                list.insert(find(list.begin(), list.end(), temp2), temp1);
            }
        }
        else if(s == "remove"){
            int temp; cin >> temp;
            if(mp[temp] == 1){
                mp[temp] = 0;
                list.erase(find(list.begin(), list.end(), temp));
            }
        }
        else if(s == "reverse"){
            reverse(list.begin(), list.end());
        }
        else{
            continue;
        }
    }

    for(auto& x:list) cout << x << " ";

    return 0;
}