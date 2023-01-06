import graphviz
a=list(map(int,input().split()))
a.append(len(a)+2)
n=len(a)
b=[0]*n
for i in range(n):
    for j in range(1,n+1):
        if j not in a[i:] and j not in b[:i]:
            b[i]=j
            break
tr= graphviz.Digraph('tree')
for i in range(1,n+2):
    tr.node(str(i))
for i in range(n):
    tr.edge(str(a[i]),str(b[i]), arrowhead="none")
tr.render()