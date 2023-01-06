from collections import Counter
N,M=map(int,input().split())
tree=Counter(map(int,input().split()))
case=[i for i in range(min(tree),max(tree)+1)]
d=dict(zip(map(lambda H:sum([(i-H)*j for i,j in tree.items() if i>H]),case),case))
print(d[min([i for i,j in d.items() if i>=M])])