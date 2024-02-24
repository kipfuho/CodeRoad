import graphviz

n, m = map(int, input().split())
tr = graphviz.Digraph('graph')
for i in range(1, n + 1):
    tr.node(str(i))
for i in range(m):
    s = input().split()  # map(int,input().split()))
    tr.edge(str(s[0]), str(s[1]))  # , arrowhead="none")
tr.render()
