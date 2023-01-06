N,k= map(int, input().split())
lst=[1]*((N+1)//2+1)
for i in range((N+1)//2):
    lst[i+1]=lst[i]*(N-i)/(i+1)
print(lst)