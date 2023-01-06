import sys;input=sys.stdin.readline #speed boost
for _ in range(int(input())):
  n,s=int(input()),input()
  spe=set([*input().split()][1:])
          
  pre=res=0
  for i in range(n):
    if s[i] in spe:
      res=max(res,i-pre)
      pre=i
  print(res)