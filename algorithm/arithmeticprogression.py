#   mininum number of elements need to be changed to make the array
#   an arithmetic progression
for _ in range(int(input())):
    n,arr=int(input()),list(map(int,input().split()))
    if n<=2:
        print('0')
        continue
    ans=2
    for i in range(n):
        for j in range(i+1,n):
            x=j-i
            y=(arr[j]-arr[i])/x
            num=2
            for k in range(n):
                if k<i:
                    if arr[k]==(arr[i]-y*(i-k)):
                        num+=1
                elif k<j and k!=i:
                    if arr[k]==(arr[i]+y*(k-i)):
                        num+=1
                elif k>j:
                    if arr[k]==(arr[j]+y*(k-j)):
                        num+=1
                else:
                    continue
            ans=max(ans,num)
    print(n-ans)