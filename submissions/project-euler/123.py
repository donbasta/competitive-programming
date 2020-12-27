
isPrime = [True for i in range(1000005)]
isPrime[0] = False; isPrime[1] = False

def generatePrime(n):
    for i in range(1,n+1):
        if isPrime[i]:
            cur = 2*i
            while(cur <= n):
                isPrime[cur] = False
                cur += i
    prime = []
    for i in range(1,n+1):
        if isPrime[i]:
            prime.append(i)
    return prime

TARGET = 1000000000
ans = None
idx = 1
'''
for i in range(10):
    print(generatePrime(1000000)[i])
'''
for i in generatePrime(1000000):
    if idx%2 != 0:
        if ((2*idx*i)%(i*i)) > TARGET:
            ans = idx
            break
    idx += 1

print(ans)