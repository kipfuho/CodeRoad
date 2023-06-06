// Nguyễn Đình Út Biu - 20215317
/*
Bài 2.11. Tính tích hai đa thức

Cho 2 đa thức A(x) và B(x) tương ứng có bậc  N và  M
Hãy tính ma trận tích C(x) = A(x) * B(x) có bậc  N+M−1

Input: Gồm 2 dòng biểu diễn các đa thức A(x) và B(x), mỗi dòng
Số đầu tiên  N là bậc của đa thức;
N+1 số nguyên tiếp theo, số thứ i là hệ số của  x^(i−1).
Output: Một số nguyên duy nhất là XOR của các hệ số của đa thức C(x).

Ví dụ:

Input:
3 83 86 77 15
4 93 35 86 92 49

Output:
20731

Giải thích: các hệ số của đa thức kết quả lần lượt là 7719, 10903, 17309, 19122, 19126, 12588, 5153, 735.

Giới hạn:
Các hệ số của các đa thức đầu vào có trị tuyệt đối nhỏ hơn 100.
Có 5 tests, test thứ i có bậc của các đa thức đầu vào không quá 10^i.
*/

// Fast Fourier Transformation

#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <fstream>

using namespace std;

typedef complex<double> base;
typedef vector<base> vb;

// Dùng file input cho đỡ lag
void input(vb &x, vb &y){
    fstream file("c/text.txt");
    int n, m;
    file >> n;
    for(int i = n + 1; i !=0; i--){
        int temp;
        file >> temp;
        x.push_back(base(temp, 0));
    }
    file >> m;
    for(int i = m + 1; i !=0; i--){
        int temp;
        file >> temp;
        y.push_back(base(temp, 0));
    }
    file.close();
}

// FFT khử đệ quy
void fft(vb &a, int n, bool invert){
    if(n == 1) return;

    // bit reversal order 
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    
    for(int len = 2; len <= n; len <<= 1){
        double ang = 2*M_PI  / len;
        if(invert) ang = -ang;
        base wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len){
            base w(1);
            for(int j = 0; j < len / 2; j++){
                base u = a[i + j], v = w*a[i + j + len / 2];
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if(invert){
        for(int i = 0; i < n; i++){
            a[i] /= n;
        }
    }
}

// Hàm tìm XOR hệ số củas tích 2 đa thức
void polynom_multiply(vb x, vb y){
    int MAX = max(x.size(), y.size()), n = 1;
    // Tìm luỹ thừa của 2 đủ lớn hơn x.size() + y.size()
    while(n < MAX){
        n <<= 1;
    }
    n <<= 1;
    
    // Chuyển các đa thức về dạng biểu diễn điểm bằng Fast Fourier Transformation
    x.resize(n);
    y.resize(n);
    fft(x, n, false);
    fft(y, n, false);

    // Nhân 2 đa thức
    vb c(n);
    for(int i = 0; i < n; i++){
        c[i] = x[i]*y[i];
    }

    // FFT reversion để lấy dạng hệ số
    fft(c, n, true);

    // Kết quả XOR các hệ số
    int res = 0;
    for(int i = 0; i < n; i++){
        res ^= (int) (real(c[i]) + 0.5);
    }
    cout << res;
}

int main(){
    vb x, y;
    input(x, y);
    polynom_multiply(x, y);
}