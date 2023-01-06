_=input()
a=list(i for i in map(int,input().split()) if i%2!=0)
print("{x:.4f}".format(x=sum(a)/len(a)))