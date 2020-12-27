c,n,p,w = map(int, input().split())

if p>c:
  ans = min(w//c, (p*n - w)//(p - c))
else:
  ans = w//c

print(ans)