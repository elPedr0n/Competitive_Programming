start = [int(i) for i in input().split()]
a, b, c = start[0], start[1], start[2]
if a < b and a < c:
    if b < c:
        print(a)
        print(b)
        print(c)
    else:
        print(a)
        print(c)
        print(b)
elif b < a and b < c:
    if a < c:
        print(b)
        print(a)        
        print(c)
    else:
        print(b)
        print(c)
        print(a)
else:    
    if a < b:
        print(c)
        print(a)
        print(b)
    else:        
        print(c)
        print(b)
        print(a)
print()
for i in start:
    print(i)
