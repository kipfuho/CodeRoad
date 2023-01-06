if __name__ == '__main__':
    N = int(input())
    lst=[]
while(N>0):
    com,*ss=input().split()
    if com!='print':
        ss=",".join(ss)
        eval('lst.'+com+'('+ss+')')
    else:
        print(lst)
    N-=1