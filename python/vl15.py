s=list(map(int,input().split()))
if s[1]==0:
    print("INVALID")
else:
    a=0
    if s[0]*s[1]<0:
        a=1
    s[0]=abs(s[0])
    s[1]=abs(s[1])
    if s[0]%s[1]==0:
        print(int(pow(-1,a)*s[0]/s[1]))
    else:
        for i in range(min(s),0,-1):
            if s[0]%i==0 and s[1]%i==0:
                print("{a} {b}".format(a=int(pow(-1,a)*s[0]/i),b=int(s[1]/i)))
                break