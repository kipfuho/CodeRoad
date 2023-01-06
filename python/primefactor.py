def factor(n, c):
    f = lambda(x): (x*x+c) % n
    t, h, d = 2, 2, 1
    while d == 1:
        t = f(t); h = f(f(h)); d = gcd(t-h, n)
    if d == n:
        return factor(n, c+1)
    return d
print factor(15227063669158801, 1)