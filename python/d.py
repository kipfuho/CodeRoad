s=input()
def check(s):
    a=0
    for i in range(len(s)//2):
        if s[i]!=s[len(s)-1-i]:
            a+=1
    if a==0:
        print(True)
    else:
        print(False)
check(s)