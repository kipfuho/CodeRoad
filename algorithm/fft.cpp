// Fast Fourier Transformation

#include <bits/stdc++.h>

using namespace std;

typedef complex<double> base;
typedef vector<base> vb;

void input(vb &x, vb &y){
    int n, m;
    cin >> n;
    for(int i = n + 1; i !=0; i--){
        int temp;
        cin >> temp;
        x.push_back(base(temp, 0));
    }
    cin >> m;
    for(int i = m + 1; i !=0; i--){
        int temp;
        cin >> temp;
        y.push_back(base(temp, 0));
    }
}

/* FFT dùng đệ quy
void fft(vb &a, int n){
    if(n == 1) return;
    
    vb a0(n / 2), a1(n / 2);
    for(i = j = 0; i < n; i+=2, j++){
        a0[j] = a[i];
        a1[j] = a[i+1];
    }

    fft(a0, n / 2);
    fft(a1, n / 2);

    double ang = 2*M_PI  / n;
    base w(1), wn(cos(ang), sin(ang));

    for(i = 0; i < n / 2; i++){
        a[i] = a0[i] + w*a1[i];
        a[i + n/2] = a0[i] - w*a1[i];
        w = w*wn;
    }
}

void inverse_fft(int n, vb& a)
{
    if(n == 1)
    {
        return;
    }

    vb a0(n / 2), a1(n / 2);
    for(i = j = 0; i < n; i+=2, j++){
        a0[j] = a[i];
        a1[j] = a[i+1];
    }

    inverse_fft(n/2, a0);
    inverse_fft(n/2, a1);

    double ang = -2*M_PI / n;
    base w (1),  wn (cos(ang), sin(ang));

    for(i = 0; i < n/ 2; ++i)
    {
        a[i] = a_even[i] + w * a_odd[i];
        a[i] /= 2;
        a[i + n / 2] = a_even[i] - w * a_odd[i];
        a[i + n / 2] /= 2;
        w *= wn;
    }
}
*/

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