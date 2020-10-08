tc = int(input())
for i in range(tc):
  ls = list(map(int, input().split()))
  avg = (ls[0] + ls[1] + 1) // 2
  if (ls[0] >= avg + 1):
    print("Tere")
  elif (ls[1] >= avg + 1):
    print("Toni")
  else:
    print("Voting Ulang")