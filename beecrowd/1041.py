xy = [float(i) for i in input().split()]
x, y = xy[0], xy[1]
if x == 0 and y == 0:
    print("Origem")
elif x > 0:
    if y > 0:
        print("Q1")
    elif y < 0:
        print("Q4")
    else:
        print("Eixo X")
elif x < 0:
    if y > 0:
        print("Q2")
    elif y < 0:
        print("Q3")
    else:
        print("Eixo X")
else:
    print("Eixo Y")