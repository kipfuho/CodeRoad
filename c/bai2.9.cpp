// Nguyễn Đình Út Biu - 20215317
/*
Bài 2.9. Tính hàm sigmoid
Dưới đây cung cấp đoạn code đơn giản để tính hàm sigmoid theo công thức trực tiếp.
Hãy viết hàm tính xấp xỉ sigmoid(x) đến độ chính xác 10^−6
và có tốc độ nhanh hơn ít nhất 30% so với code đơn giản.
Gợi ý: sử dụng kỹ thuật "chuẩn bị trước" như trong slide.
*/

#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>

using namespace std;

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];

// Hàm khởi tạo x đã giới hạn giá trị của x vào (-RANGE; RANGE) hay (-5, 5) khi LIMIT = 100
void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}

//# BEGIN fast code

//# khai báo các biến phụ trợ cần thiết
double delta = 0.000001; // bước nhảy delta = 1*10^-6
double SIGMOID[10000001]; // Mảng tính trước với hơn 20 triệu phần tử
double X0 = -5; // X0 khởi đầu, Lowerbound; Upperbound = 5

//# hàm chuẩn bị dữ liệu
void precalc() {
    int i = 0; 
    double foo = X0;;
    while(foo < 5){
        SIGMOID[i++] = sigmoid_slow(foo);
        foo += delta;
    }
}

//# hàm tính sigmoid(x) nhanh sigmoid_fast(x)
// Không cần xét TH x > 5 và x < -5 nhờ hàm prepare_input
inline double sigmoid_fast(double x) {
    int index = (x + 5)*1000000; // = (x - X0) / delta
    return SIGMOID[index];
}

//# END fast code

// Benchmark cho 2 cách nhanh và chậm
double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;

    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);

    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
  printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}

// Xem kết quả tính nhanh có hợp lệ
bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;

    if (a.size() != b.size()) return false;
    for (unsigned int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}

int main() {
    prepare_input();
    precalc();

    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);

    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));
    
    if (is_correct(a, b) && (slow/fast) > 1.3) {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    } else {
        printf("Wrong answer or your code is not fast enough!\n");
    }
    
    return 0;
}