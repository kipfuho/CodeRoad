import math
N,k=map(int, input().split())
total=0
for i in range(1,N+1):
    total+=(math.comb(N,i)*pow(i,k))
a=total%1000000007
print(a)