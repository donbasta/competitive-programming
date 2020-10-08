ar = [0,3,3,5,4,4,3,5,5,4]
be = [3,6,6,8,8,7,7,9,9,8]

def calc(x):
  if x < 10:
    return ar[x]
  elif x >= 10 and x < 20:
    return be[x - 10]
  elif x < 100:
    
