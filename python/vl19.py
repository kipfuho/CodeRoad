s=list(map(int,input().split()))
a=0
for i in range(s[1]-1,s[0],-1):
    if i%3==0:
        print(i,end=' ')
        a=a+1
if a==0:
	print("NOT FOUND")