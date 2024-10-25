import sys

s = input()

for i in range(len(s)):
    if s[i] != 'E' and s[i] != 'O':
        print("INVALID")
        sys.exit(0)
    if i < len(s) - 1 and s[i] == 'O' and s[i + 1] == 'O':
        print("INVALID")
        sys.exit(0)
    if i == len(s) - 1 and s[i] == 'E':
        print("INVALID")
        sys.exit(0)

B = 100
for i in range(4, B, 2):
    cur = 2 ** i
    cur = (cur - 1) // 3
    ok = True
    for j in range(len(s) - 1, -1, -1):
        parity = 0 if s[j] == 'E' else 1
        if cur % 2 != parity:
            ok = False
            break
        if j > 0:
            next_parity = 0 if s[j - 1] == 'E' else 1
            if next_parity == 1:
                if cur % 3 != 1:
                    ok = False
                    break
                cur = (cur - 1) // 3
            else:
                cur = cur * 2
    if ok:
        print(cur)
        sys.exit(0)
assert False
