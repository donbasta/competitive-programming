a = 1
b = 1
MAX = 2000000000000

while a <= MAX:
    a1 = 3*a + 4*b
    b1 = 2*a + 3*b
    a = a1; b = b1

print((b+1)//2)