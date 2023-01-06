a=[]
b=[]
for i in range(100):
    a.append(int(input()))
for i in range(100):
    b.append(int(input())) 
print("lon")  
for i in a:
    if i not in b:
        print(i)