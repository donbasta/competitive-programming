tc = int(input())

for _ in range(tc):
    n = int(input())
    moves = input().split()
    ada = [-1 for i in range(n + 5)]
    ok = True
    for i in range(n):
        tok = moves[i].split('e')
        if int(tok[0]) > n:
            ok = False
            break
        ada[int(tok[0])] = int(tok[1])

    for i in range(1, n + 1):
        if ada[i] == -1:
            ok = False
            break

    first_move = (ada[1] == 3 or ada[1] == 4)
    second_move = (ada[2] == 5 or ada[2] == 6)

    if n == 1:
        ok = ok and first_move
    elif n == 2:
        ok = ok and first_move and second_move
    elif n == 3:
        ok = ok and first_move and second_move
        if ada[1] == 4 and ada[2] == 5:
            ok = False
        elif ada[1] == 4 and ada[2] == 6:
            ok = ok and (ada[3] == 5)
        elif ada[1] == 3 and ada[2] == 5:
            ok = ok and (ada[3] == 4)
        elif ada[1] == 3 and ada[2] == 6:
            ok = ok and ((ada[3] == 4) or (ada[3] == 5))
    elif n == 4:
        ok = ok and (ada[1:5] == [3, 6, 4, 5])
    else:
        assert False

    if not ok:
        print("INVALID")
    else:
        print("VALID")
