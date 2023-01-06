_=input()
s=list(map(int,input().split()))
s.append(0)
for i in range(len(s)-1):
    if i%2!=0:
        s[i]=s[i]+abs(s[i-1]-s[i+1])
print(*s[:-1])