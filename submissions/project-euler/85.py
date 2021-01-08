MX = 2000
SX = 8000000

mn = 1000000000000000000
area = -1

for i in range(1, MX + 1):
    tmp = SX / (i*(i+1))
    l = 1; r = MX
    while l < r:
        mid = (l+r) // 2
        if mid * (mid+1) >= tmp:
            r = mid
        else:
            l = mid+1
    c1 = abs(l*(l+1)*i*(i+1) - SX)
    c2 = abs((l-1)*l*i*(i+1) - SX)
    if c1 < mn:
        mn = c1
        area = i*l
    if c2 < mn:
        mn = c2
        area = i*(l-1)

print("Area is: {}".format(area))