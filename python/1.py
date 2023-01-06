def print_rangoli(size):
    width=size*4-3
    s=''
    for i in range(1,size+1):
        for j in range(0,i):
            s+=chr(96+size-j)
            if len(s)<width:
                s+='-'
        for k in range(i-1,0,-1):
            s+=chr(97+size-k)
            if len(s)<width:
                s+='-'
        print(s.center(width,'-'))
        s=''
    for i in range(size-1,0,-1):
        for j in range(0,i):
            s+=chr(96+size-j)
            if len(s)<width:
                s+='-'
        for k in range(i-1,0,-1):
            s+=chr(97+size-k)
            if len(s)<width:
                s+='-'
        print(s.center(width,'-'))
        s=''

print_rangoli(5)