N,k=input(),int(input())
for part in zip(*[iter(N)]*k):
    d=dict()
    print(''.join([d.setdefault(c,c) for c in part if c not in d]))
    print(d)
