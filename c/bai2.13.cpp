// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 13: Big Integer
Số nguyên lớn là các số nguyên có giá trị rất lớn và không thể biểu diễn bằng các kiểu dữ liệu nguyên cơ bản. Để biểu diễn số nguyên lớn, ta có thể dùng kiểu struct như sau:

struct bigNum{
    char sign;
    char num[101];
};

Nhiệm vụ các bạn là đa năng hóa các toán tử để thực hiện các phép toán số học với kiểu dữ liệu số nguyên lớn vừa định nghĩa ở trên.

Input: Dữ liệu vào gồm hai dòng mô tả hai số nguyên lớn a và b, mỗi dòng chứa 1 chuỗi ký tự mô tả 1 số nguyên lớn không vượt quá 10^100. Chữ số đầu của mỗi chuỗi ký tự sẽ thể hiện dấu của số đó: 0 là âm, 1 là dương. Các chữ số sau thể hiện giá trị của số đó.
Output: In ra giá trị của biểu thức  ab−3a+4b. Kết quả in ra một số nguyên lớn dưới dạng chuỗi ký tự có định dạng như mô tả trong dữ liệu vào.

Ví dụ:
Input:
0121807015
1347227347
Output:
042294724910108772
*/

#include <iostream>

using namespace std;

struct bigNum{
    char sign;
    char num[151];
};

// Điền dữ liệu cho a từ number
void input(bigNum &a, string number){
    int len = number.size() - 1, j = 1;
    a.sign = number[0];
    for(int i = 150 - len + 1; i <= 150; i++){
        a.num[i] = number[j++];
    }
    for(int i = 150 - len; i != -1; i--){
        a.num[i] = '0';
    }
}

// Cộng 2 số dương, c = a + b
void add(char* a, char* b, char c[]){
    int carry = 0;

    for(int i = 150; i != -1; i--){
        int temp = (int) a[i] - 48 + (int) b[i] - 48 + carry;
        carry = temp / 10;
        c[i] = temp % 10 + 48;
    }
}

// Trừ 2 số dương, c = a - b
void sub(char* a, char* b, char c[]){
    int carry = 0;

    for(int i = 150; i != -1; i--){
        int temp1 = (int)a[i] - 48;
        int temp2 = (int)b[i] - 48;

        if(temp1 >= temp2 + carry){
            c[i] = temp1 - temp2 - carry + 48;
            carry = 0;
        } else {
            temp1 = temp1 + 10;
            c[i] = temp1 - temp2 - carry + 48;
            carry = 1;
        }
    }
}

// Nhân 2 số dương c = a * b
void multi(char* a, char* b, char c[]){
    // Khởi tạo c
    for(int i = 0; i <= 150; i++) c[i] = '0';

    // Nhân theo từng hàng của a
    for(int i = 150; i != -1; i--){
        char temp[151];
 
        int k;
        for(k = 0; k < i; k++) temp[150-k] = '0';

        int carry = 0, sum = 0;
        for(int j = 150; j != -1; j--){
            sum = ((int)a[i] - 48) * ((int)b[j] - 48) + carry;
            temp[k] = (sum % 10) + 48;
            carry = sum / 10;
            k--; if(k < 0) break;
        }

        add(c,temp,c);
    }
}

// So sánh a và b, loại trừ dấu
bool compare(char* a, char* b) {
    int len1 = 0, len2 = 0;
    for(int i = 150; i != -1; i--){
        if(a[i] != '0') len1++;
    }
    for(int i = 150; i != -1; i--){
        if(b[i] != '0') len2++;
    }
    if(len1 > len2) return true;
    if(len1 == len2){
        int j = len1;
        while(a[j] == b[j]) j++;
        if(a[j] > b[j]) return true;
    }
    return false;
}

bigNum operator + (bigNum a, bigNum b) {
    bigNum temp;
    // Cộng 2 số âm
    if(a.sign == '0' && b.sign == '0'){
        temp.sign = '0';
        add(a.num, b.num, temp.num);
    }
    // Cộng 2 số dương
    else if(a.sign == '1' && b.sign == '1'){
        temp.sign = '1';
        add(a.num, b.num, temp.num);
    }
    // Cộng 2 số khác dấu
    else{
        if(compare(a.num, b.num)){
            temp.sign = a.sign;
        }
        else{
            temp.sign = b.sign;
        }
        sub(a.num, b.num, temp.num);
    }
    return temp;
}

bigNum operator - (bigNum a, bigNum b) {
    bigNum temp;
    // Trừ 2 số âm
    if(a.sign == '0' && b.sign == '0'){
        if(compare(a.num, b.num)){
            temp.sign = a.sign;
        }
        else{
            temp.sign = b.sign;
        }
        sub(a.num, b.num, temp.num);
    }
    // Trừ 2 số dương
    else if(a.sign == '1' && b.sign == '1'){
        if(compare(a.num, b.num)){
            temp.sign = a.sign;
        }
        else{
            temp.sign = b.sign;
        }
        sub(a.num, b.num, temp.num);
    }
    // Số âm trừ số dương
    else if(b.sign == '1'){
        temp.sign = '0';
        add(a.num, b.num, temp.num);
    }
    // Số dương trừ số âm
    else{
        temp.sign = '1';
        add(a.num, b.num, temp.num);
    }
    return temp;
}

bigNum operator * (bigNum a, bigNum b) {
    bigNum temp;
    // Nhân 2 số âm
    if(a.sign == '0' && b.sign == '0'){
        temp.sign = '1';
        multi(a.num, b.num, temp.num);
    }
    // Nhân 2 số dương
    else if(a.sign == '1' && b.sign == '1'){
        temp.sign = '1';
        multi(a.num, b.num, temp.num);
    }
    // Nhân 2 số trái dấu
    else{
        temp.sign = '0';
        multi(a.num, b.num, temp.num);
    }
    return temp;
}

// Thay đổi outstream để cout
ostream& operator << (ostream& out, const bigNum &a) {
    int len = 0;
    for(int i = 0; i <= 150; i++){
        if(a.num[i] != '0') break;
        len++;
    }
    out << a.sign;
    for(int i = len; i <= 150; i++){
        out << a.num[i];
    }
    return out;
}

int main(){
    string temp;
    bigNum a, b, so3, so4;
    // Lấy 2 số a, b
    cin >> temp;
    input(a, temp);
    cin >> temp;
    input(b, temp);
    // Khởi tạo 2 số 3, 4
    input(so3, "13\0");
    input(so4, "14\0");
    cout << a*b - so3*a + so4*b;
}