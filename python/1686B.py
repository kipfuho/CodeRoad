import sys;input=sys.stdin.readline #speed boost
for _ in range(int(input())):
    n,arr=int(input()), list(map(int,input().split()))
    i=total=0
    if n==1:
        print(0)
    else:
        while True:
            i+=1
            if i>=n:
                break
            if arr[i]<arr[i-1]:
                total+=1
                i+=1
        print(total)