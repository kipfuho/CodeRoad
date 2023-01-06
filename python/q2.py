t=0
for a in range(1,8):
    for b in range(7):
        for c in range(7):
            for d in range(7):
                if a+b+c+d==7:
                    t+=1
print(t)     