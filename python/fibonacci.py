f=[0]*46
f[1]=1
f[2]=1
for i in range(3,46):
    f[i]=f[i-1]+f[i-2]
print(f[45])