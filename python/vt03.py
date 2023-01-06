n=int(input())
s=list(map(int,input().split()))
print(max(i for i in range(n) if s[i]==max(s)))