MX = 50000000

primes = []
# po2 = [False for _ in range(MX+1)]
po2 = []
po3 = []
po4 = []

def sieve():
    pr = [True for _ in range(MX+1)]
    pr[1] = False
    for i in range(2, MX+1):
        if not pr[i]:
            continue
        primes.append(i)
        for j in range(2*i, MX+1, i):
            pr[j] = False

def isi():
    for i in primes:
        if i**4 > MX:
            break
        po4.append(i**4)
    for i in primes:
        if i**3 > MX:
            break
        po3.append(i**3)
    for i in primes:
        if i**2 > MX:
            break
        # po2[i**2] = True
        po2.append(i**2)

def main():
    sieve()
    isi()
    ans = set()

    for i in po2:
        for j in po3:
            for k in po4:
                if i+j+k < MX:
                    ans.add(i+j+k)

    print(len(ans))

    # for i in range(50, MX+1):
    #     if i % 100000 == 0:
    #         print("Cek: {}".format(i))
    #     for j in po4:
    #         if j >= i:
    #             break
    #         for k in po3:
    #             if j+k >= i < 0:
    #                 break
    #             cek = i-j-k
    #             if po2[cek]:
    #                 ans = ans+1

    # print(ans)

main()