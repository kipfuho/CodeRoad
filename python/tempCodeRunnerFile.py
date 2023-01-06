a,b=map(int,input().split())
m=0
for i in range(1,a+1):
    if 4*a-2*i == 0:
        print(i,a-i,sep=' ')
        m=1
        break
if m!=0:
    print(-1)