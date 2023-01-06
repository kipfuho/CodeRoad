s=list(map(str,input().split()))
if s[10] not in set(s[:10]):
    print(-1)
else:
    print(" ".join([str(i+1) for i in range(10) if s[i]==s[10]]))