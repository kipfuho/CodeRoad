#define MOD 1000000007

// Extended Euclidean algorithm
int xGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (long long)(a / b) * y1;
    return gcd;
}

// factorial of n modulo MOD
int modfact(int n) {
    int result = 1;
    while (n > 1) {
        result = (long long)result * n % MOD;
        n -= 1;
    }
    return result;
}

// multiply a and b modulo MOD
int modmult(int a, int b) {
    return (long long)a * b % MOD;
}

// inverse of a modulo MOD
int inverse(int a) {
    int x, y;
    xGCD(a, MOD, x, y);
    return x;
}

// binomial coefficient nCk modulo MOD
int bc(int n, int k)
{
    return modmult(modmult(modfact(n), inverse(modfact(k))), inverse(modfact(n - k)));
}

// modular exponentiation a^n modulo MOD
long long mod_pow(int a,int n)
{
    long long ret=1;
    long long A=a;
    while(n)
    {
        if (n & 1)
            ret=(ret*A)%MOD;
        A=(A*A)%MOD;
        n>>=1;
    }
    return ret;
}
