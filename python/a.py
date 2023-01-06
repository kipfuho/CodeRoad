a = int(input())
b = int(input())

def power(a, b):
    c=1
    if b>=1:
        while b>=1:
            c*=a
            b-=1
        return c
    elif b==0:
        return 1
    elif b<0:
        return 1/power(a,-b)
print(power(a, b))