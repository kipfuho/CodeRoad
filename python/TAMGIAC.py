c=list(map(int,input().split()))
x=sum(c)/2
if c[0]+c[1]>c[2] and c[1]+c[2]>c[0] and c[2]+c[0]>c[1]:
    print("{p} {s:.2f}".format(p=c[0]+c[1]+c[2],s=pow(x*(x-c[0])*(x-c[1])*(x-c[2]),1/2)))
else:
    print("NO")