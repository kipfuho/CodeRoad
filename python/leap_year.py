y=int(input())
if y<=0 or y>100000:
    print("INVALID")
elif y%100==0:
    if y%400==0:
        print("YES")
    else:
        print("NO")
else:
    if y%4==0:
        print("YES")
    else:   
        print("NO")