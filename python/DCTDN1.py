n=int(input())
a=list(map(int,input().split()))
l=[1]*n
for i in range(1,n):
    for j in range(i):
        if a[i]>a[j]:
            l[i]=max(l[i],l[j]+1)
print(max(l))