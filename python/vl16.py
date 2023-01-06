s=list(map(int,input().split()))
a=abs(s[0])
b=abs(s[1])
i=max(a,b)
while 0==0:
    if i%a==0 and i%b==0:
        print(i)
        break
    i=i+1