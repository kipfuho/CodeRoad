import graphviz



def graph_1():
    g = graphviz.Graph('graph', filename = 'graph', engine = 'sfdp')
    while True:
        s = input()
        if s == '***':
            break
        g.node(s)
    while True:
        s = input()
        if s == '***':
            break
        s = s.split()
        g.edge(str(s[1]), str(s[0]))
    g.render()

def graph_2():
    vertices = []
    g = graphviz.Digraph('graph', filename = 'graph')
    while True:
        s = input()
        if s == '***':
            break
        vertices.append(s)
        g.node(s)
    weight = lambda x, y: sum(1 for i in range(len(x)) if x[i] == y[i] )
    for x in vertices:
        for y in vertices:
            if x[1:] == y[:3]:
                g.edge(x, y, label = str(weight(x, y)))
    g.render()

def edges_list():
    vertices = []
    while True:
        s = input()
        if s == '***':
            break
        vertices.append(s)   
    
