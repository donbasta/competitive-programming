
#banyaknya hamming dengan prime factor pada t dan not exceeding n
def hamming(t,n):
    if t:
        cur = 1; ans = 0
        while cur <= n:
            ans += hamming(t[1:],n//cur)
            cur *= t[0]
        return ans
    else:
        return 1

def generatePrime(n):
    isPrime = [True for i in range(1000005)]
    isPrime[0] = False; isPrime[1] = False
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

MAX = 1000000000
prima = generatePrime(100)
#print(prima)
#prima = [2,3,5]
print(hamming( prima ,MAX))