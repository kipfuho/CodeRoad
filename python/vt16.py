s=list(map(int,input().split()))
a=sum(1 for i in s if i<0)
if a==0:
    print("NOT FOUND")
else:
    print(*[i for i in s if i<0])