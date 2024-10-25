tc = int(input())

for _ in range(tc):
    n = int(input())
    moves = input().split()
    ada = [-1 for _ in range(n + 5)]
    ok = True
    for i in range(n):
        tok = moves[i].split('e')
        if int(tok[0]) != i + 1:
            ok = False
        else:
            ada[int(tok[0])] = int(tok[1])

    if not ok:
        print("INVALID")
        continue

    if n == 1:
        ok = (ada[1] == 3) or (ada[1] == 4)
    elif n == 2:
        ok = (ada[1:3] == [3, 6]) or (ada[1:3] == [3, 5]) or (
            ada[1:3] == [4, 6]) or (ada[1:3] == [4, 5])
    elif n == 3:
        cand = [
            [3, 6, 4],
            # [3, 6, 5],
            [3, 5, 4],
            [4, 6, 5],
        ]
        ok = (ada[1:4] in cand)
    elif n == 4:
        ok = (ada[1:5] == [3, 6, 4, 5])
    else:
        assert False

    if not ok:
        print("INVALID")
    else:
        print("VALID")
