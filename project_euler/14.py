sum = 0

with open('14.txt', 'r') as nums:
    num = nums.readline()
    while num:
        sum += int(num)
        num = nums.readline()

print(sum)