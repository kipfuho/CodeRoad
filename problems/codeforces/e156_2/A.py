t = int(input())
for _ in range(t):
    n = int(input())
    if n < 10:
        if n == 7:
            print("YES")
            print("1 2 4")
        elif n == 8:
            print("YES")
            print("1 2 5")
        else:
            print("NO")
    else:
        floor = (n // 3) - 1
        mod = n % 3
        print("YES")
        if mod == 0:
            print(*[1, 4, floor + floor + floor - 2])
        else:
            print(*[mod, 4, floor + floor + floor - 1])