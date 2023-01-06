t=int(input())
for _ in range(t):
    n=int(input())
    a=sum(map(int,input().split()))-n
    if a%2==0:
        print("maomao90")
    else:
        print("errorgorn")