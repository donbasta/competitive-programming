with open("p083_matrix.txt") as file:
    lines = file.readlines()
    mat = [line.split(",") for line in lines]

sz = len(mat)
assert sz == 80

