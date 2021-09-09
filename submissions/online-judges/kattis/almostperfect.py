value=[]
sumVal=[]
counter = 0
conclusions = []

while True:
    try:
        x = int(input())
        value.append(x)
    except:
        break
    
for item in value:
    temp = item - 1 
    x = 2
    sumVal.append(0)
    while x < temp:
        if item % x == 0:
            # sumVal.append(0)
            sumVal[counter] = sumVal[counter] + x + (item/x)
            temp = item/x
        x += 1
    sumVal[counter] += 1
    if sumVal[counter] == item:
        conclusions.append(' perfect ')
    elif sumVal[counter] >= item - 2 :
        conclusions.append(' almost perfect ')
    else:
        conclusions.append(' not perfect ') 
    print(str(item) + conclusions[counter])    
    counter += 1