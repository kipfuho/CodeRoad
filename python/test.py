a=0
for i in range(1,2010):
    if i%11!=0 and i%13!=0 and i%15!=0 and i%17!=0:
        a=a+1
print(a)