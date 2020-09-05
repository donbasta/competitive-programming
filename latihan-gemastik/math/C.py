def C(a, b):
  ret = 1
  div = 1
  for i in range(1, b + 1):
    ret = ret * (a - b + i)
    div = div * i
  return ret // div

a = int(input())
ans = C(a, 5) + C(a, 6) + C(a, 7)
print(ans)