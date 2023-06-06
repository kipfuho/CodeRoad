// Nguyễn Đình Út Biu - 20215317
/*
Bài 2.12. Map Sort
Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. Cô cho một danh sách với mỗi phần tử có dạng <key, value> và yêu 
cầu An sắp xếp danh sách đó giảm dần theo giá trị value. Nếu 2 phần tử có value giống nhau thì sắp xếp giảm dần theo key.

Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.

Input: Danh sách đầu vào. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách (|key| ≤ 10^9, |value| ≤ 10^9).
Output: In danh sách đã được sắp xếp theo yêu cầu. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách.

Ví dụ:
Input:
2 3
4 8
9 1
1 8
Output:
4 8
1 8
2 3
9 1
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    vector<vector<int>> MAP;
    // Hàm nặc danh compare
    auto compare = [&](vector<int> a, vector<int> b){
        if(a[1] > b[1]) return true;
        if(a[1] == b[1]){
            if(a[0] > b[0]) return true;
        }
        return false;
    };
    // Lấy input
    fstream file("c/text.txt");
    int temp1, temp2;
    while(file >> temp1 && file >> temp2){
        vector<int> temp = {temp1, temp2};
        MAP.push_back(temp);
    }
    file.close();

    // Sắp xếp dùng hàm nặc danh compare làm tham số
    sort(MAP.begin(), MAP.end(), compare);
    for(auto& x : MAP){
        cout << x[0] << " " << x[1] << endl;
    }
}