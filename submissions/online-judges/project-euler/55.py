def rev(n):
    return str(n)[::-1]

def is_palindrome(n):
    return str(n) == rev(n)

ans = 1


for i in range(1, 10000):
    # if i % 100 == 0:
    #     print(i)
    ok = False
    itr = 0
    cur = i
    printed = False
    if i == 349:
        printed = True
    while itr <= 49:
        if printed:
            print (cur)
        cur = cur + int(rev(cur))
        itr += 1
        if is_palindrome(cur):
            ok = True
            break
    if not ok:
        ans += 1

print(ans)

print(is_palindrome(123))