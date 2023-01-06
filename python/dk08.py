s=input().split()
if s[1]=="/" and eval(s[2])==0:
    print("Math Error")
else:
    print("{a:.2f}".format(a=eval("".join(s))))