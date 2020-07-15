import math

with open('base_exp.txt') as be:
    baris = be.readlines()
    arr = [x.split(',') for x in baris]


line = 1; ans = 1; maks = 0; t = [None,None]
for i in arr:
    i1 = int(i[0]); i2 = int(i[1])
    if maks < (i2*math.log10(i1)):
        ans = line
        maks = (i2*math.log10(i1))
        t[0] = i1; t[1] = i2
    line += 1

print(ans)
print(t)