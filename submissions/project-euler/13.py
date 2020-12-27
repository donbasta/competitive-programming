'''
faktor = [0,1]

for i in range(2,500000):
    ans = 2
    for j in range(2,i+1):
        if(j*j > i):
            break
        else:
            if(i%j == 0):
                if(j*j==i):
                    ans += 1
                else:
                    ans += 2
    faktor.append(ans)

def countFactorTriangular(x):
    if x%2==0:
        return faktor[x//2]*faktor[x+1]
    else:
        return faktor[(x+1)//2]*faktor[x]

t = int(input("Masukkan nilai: "))
n = 1

while(countFactorTriangular(n)<=500):
    n+=1

'''
print(12375*(12376)/2)
