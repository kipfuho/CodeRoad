import math
t = int(input())
for _ in range(t):
    n = int(input())
    total = 0
    prev = 0
    coeff = 0
    for _ in range(n):
        temp = int(input())
        if temp >= prev:
            continue
        coeff = int(math.log2((prev - 1)/temp)) + 1
        total += coeff
        prev = temp*pow(2, coeff)
    print(total)
