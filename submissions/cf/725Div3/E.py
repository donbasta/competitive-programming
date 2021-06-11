def add(u, v):
    tot = u[0] + v[0]
    tot += (u[1] == "h" and v[4] == "aha")
    tot += (u[2] == "ha" and v[5] == "ha")
    tot += (u[3] == "hah" and v[6] == "a")

    ret = [None for i in range(8)]
    ret[0] = tot
    ret[7] = u[7] + v[7]

    ret[6] = u[6]
    if (u[7] == 1):
        ret[5] = u[6] + v[6]
    else:
        ret[5] = u[5]  
    if (u[7] == 1 and v[7] >= 2):
        ret[4] = u[6] + v[5]
    elif (u[7] == 2):
        ret[4] = u[5] + v[6]  
    else:
        ret[4] = u[4]

    ret[1] = v[1]
    if (v[7] == 1):
        ret[2] = u[1] + v[1]
    else:
        ret[2] = v[2]  
    if (v[7] == 1 and u[7] >= 2):
        ret[3] = u[2] + v[1]
    elif (v[7] == 2):
        ret[3] = u[1] + v[2]  
    else:
        ret[3] = v[3]

    return ret

def process(u):
    ret = [None for i in range(8)]
    haha = 0
    for i in range(len(u) - 3):
        if (u[i:i+4] == "haha"):
            haha += 1
    ret[0] = haha
    ret[7] = len(u)
    ret[1] = u[-1]
    ret[6] = u[0]
    if (ret[7] >= 2):
        ret[2] = u[-2:]
        ret[5] = u[:2]
    if (ret[7] >= 3):
        ret[3] = u[-3:]
        ret[4] = u[:3]
    return ret

tc = int(input())
for _ in range(tc):
    n = int(input())
    val = {}
    last = ""
    for _ in range(n):
        u = input()
        u = u.split()
        if len(u) == 3:
            val[u[0]] = process(u[2])
        elif len(u) == 5:
            val[u[0]] = add(val[u[2]], val[u[4]])
        last = val[u[0]][0]

    print(last)