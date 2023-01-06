from itertools import product
K,M=map(int,input().split())
P=list(product(*[list(map(int,input()[1:].split()))for _ in range(K)]))
print(max(list(map(lambda x:sum(i**2 for i in x)%int(M) ,P))))