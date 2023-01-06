t=int(input())
for _ in range(t):
    l1,r1,l2,r2=map(int,input().split())
    lst1={i for i in range(l1,r1+1)}
    lst2={_ for _ in range(l2,r2+1)}
    lst3=lst1.intersection(lst2)
    if len(lst3)==0:
        print(l1+l2)
    else:
        print(min(lst3))