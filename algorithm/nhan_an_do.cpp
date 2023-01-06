#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//A x B mod M
long long multiply_modulo(long long A, long long B, long long M)
{
    if (B == 0)
        return 0;

    long long T = multiply_modulo(A, B / 2LL, M) % M;

    if (B & 1)
        return ((T + T) % M + A % M) % M;
    else
        return (T + T) % M;
}

//A^B mod M
int power_modulo_1(int A, int B, int M) // M<=10^9 
{
    if (B == 0)
        return 1LL;

    int half = power_modulo_1(A, B / 2, M) % M;

    if (B & 1)
        return (half * half * A) % M;
    else
        return (half * half) % M;
}

long long power_modulo(long long A, long long B, long long M) // M<=10^18
{
    if (B == 0)
        return 1LL;

    long long half = power_modulo(A, B / 2LL, M) % M;
    long long full = multiply_modulo(half, half, M);

    if (B & 1)
        return multiply_modulo(full, A, M);
    else
        return full;
}

int main()
{
    int A, B, M;
    cin >> A >> B >> M;
    cout << multiply_modulo(A, B, M);
}