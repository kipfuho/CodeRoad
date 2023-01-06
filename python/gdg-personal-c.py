N,M=map(int,input().split())
tree=list(map(int,input().split()))
l,r,s,c=0,0,0,0
while r<N:
    s+=tree[r]
    while s>=M:
        c+=N-r
        s-=tree[l]
        l+=1
    r+=1
print(c)