def area(a,b,c):
	return abs(a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]))/2.0

def contains_origin(a,b,c):
	origin = [0,0]
	a1 = area(a,b,origin)
	a2 = area(b,c,origin)
	a3 = area(c,a,origin)
	return a1+a2+a3 == area(a,b,c)

with open('triangles.txt') as be:
    baris = be.readlines()
    arr = [x.split(',') for x in baris]

cnt = 0
for triangles in arr:
	a = [int(i) for i in triangles[0:2]]
	b = [int(i) for i in triangles[2:4]]
	c = [int(i) for i in triangles[4:6]]
	if(contains_origin(a,b,c)):
		cnt += 1

print(cnt)
