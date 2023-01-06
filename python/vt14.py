_=input()
s=list(map(int,input().split()))
s=sorted(s)
print(max(s[-1]*s[-2],s[0]*s[1]))