t = int(input())

for tc in range(t):
  a, b, n, p = list(map(int, input().split()))
  lol = a / b
  s = str(lol - int(lol))[2:]
  print(s)
  while len(s) < n:
    s.append('0')

  cnt = [0 for i in range(200)]
  temp = 0
  cnt[temp] += 1
  for i in range(n):
    dig = ord(s[i]) - ord('0')
    temp = (temp * 10 + dig) % p
    cnt[temp] += 1

  for i in range(p):
    ans = ans + cnt[i] * (cnt[i] - 1) // 2

  print(ans)
