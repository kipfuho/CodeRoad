k = int(input())
p = list(map(int, input().split()))
c = int(input())
n = 1;
for pi in p:
	n *= pi
x3 = c % n
print(round(pow(x3, 1/3)))