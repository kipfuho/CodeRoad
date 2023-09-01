from math import isqrt

t = int(input())
for _ in range(t):
    x = int(input())
    
    n = (isqrt(8*x - 7) + 1) // 2
    r = (n*n + n + 2 - 2*x) // 2
    c = (2*x - n*n + n) // 2
    
    tk = (2*r*c*c*c + 3*c*c*r*(r+1) + c*(2*r*r*r - 3*r*r + 5*r)) // 12
    
    print(tk)