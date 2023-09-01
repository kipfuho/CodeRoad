n, m = map(int, input().split())
s = input()
for _ in range(m):
    l, r = map(int, input().split())
    max = 0
    sum = 0
    for c in s:
        if c == '+':
            sum++
        else:
            sum--
        max = max(max, abs(sum))
    print(max + 1)