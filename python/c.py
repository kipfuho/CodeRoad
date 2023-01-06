n=5
temp=0
lst=[1,2,3,4,5]
for i in range(n):
    for j in range(temp,n):
        print("sum:",sum(lst[i:j]))
