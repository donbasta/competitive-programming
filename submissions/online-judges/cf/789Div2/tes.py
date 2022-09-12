def Problem16(tc):
    for n in tc:
        if n == 1:
            print(1)
        else:
            a, b, step = 2, (n // 2), 2
            pw2 = [2 ** i for i in range(30)] #precompute power of 2
            while b > 1:
                if step % 2 == 0 and b % 2 == 0:
                    a += pw2[step - 1]
                b = (n // pw2[step])
                if (n % pw2[step]) >= a:
                    b += 1
                step += 1
            print(a)

Problem16([55, 2048, 1048576])
