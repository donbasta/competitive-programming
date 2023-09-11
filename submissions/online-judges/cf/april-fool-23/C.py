from math import pi, floor

arr = "3141592653589793238462643383279502884197"

tc = int(input())
for i in range(tc):
    ans = 1
    for j in range(int(arr[i])):
        ans *= int(input())
    print(ans)
