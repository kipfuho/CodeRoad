#include<bits/stdc++.h>
using namespace std;

class TaiKhoan{
    private:
    string Ma_so_tai_khoan="123456";
    string Ten_chu_tai_khoan="Nguyen Van Tam";
    int so_tien=10000000;
    public:
    string get_mstk(){
        return Ma_so_tai_khoan;
    }
    string get_ten(){
        return Ten_chu_tai_khoan;
    }
    int get_tien(){
        return so_tien;
    }
    void set_mstk(string a){
        Ma_so_tai_khoan=a;
    }
    void set_ten(string b){
        Ten_chu_tai_khoan=b;
    }
    void set_tien(int c){
        so_tien=c;
    }
};

int main(){
    TaiKhoan a;
    cout<<a.get_mstk()<<endl<<a.get_ten()<<endl<<a.get_tien();
}
