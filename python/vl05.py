n=int(input())
a=[0]*(n+1)
a[0]=-2
a[1]=4
for i in range(2,n):
    if i%2==0:
        a[i]=a[i-2]-3
    else:
        a[i]=a[i-2]+3
print(a[n-1])