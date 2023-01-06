#g(x)=(x1+x2+x3+....+xk)^n

a=[1 for _ in range(16)] #k+1
b=[0 for _ in range(41)]
c=[0 for _ in range(41)]
for i in range(16):
    b[i]=1
for _ in range(9): # n-1
    for i in range(16):
        for j in range(41):
            if i+j<41:
                c[i+j]=c[i+j]+b[j]
    b=c
    c=[0 for _ in range(41)]
print(b)