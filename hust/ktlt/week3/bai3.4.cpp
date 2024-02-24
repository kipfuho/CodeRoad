// Nguyen Dinh Ut Biu 20215317
// Bai3.4: Cho dãy a có n phần tử. Một dãy con của a là dãy thu được bằng 
// cách xóa đi một số phần tử của a và giữ nguyên thứ tự các phần tử còn lại 
// (có thể không xóa phần tử nào). Hãy tìm dãy con tăng dài nhất của a

#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mang ghi nho loi giai c�c b�i to�n con d� duoc giai

void init(){
    memset(mem, -1, sizeof(mem));
    mem[0] = 1;
}

//# Quy hoach dong, 
//# H�m lis(i) tra ve do d�i d�y con tang d�i nhat ket th�c boi a[i]
int lis(int i) {
	// Neu da tim duoc loi giai cap i, tra ve no
    if(mem[i] > 0) return mem[i];
    // Khai bao do dai day con lon nhat bang 1 (la chinh a[i])
    int currMax = 1;
    for(int j = 0; j < i; j++){
    	// Neu a[i] > a[j], day con lon nhat moi bang max(lis(j) + 1, currMax)
        if(a[i] > a[j]){
            if(lis(j) + 1 > currMax){
                currMax = lis(j) + 1;
            }
        }
    }
    // Ghi nho loi giai
    mem[i] = currMax;
    return currMax;
}

//# Truy vet loi giai
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
