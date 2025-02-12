t = int(input())
l = 0
for k in range(t):
    string = input()
    l = len(string)
    repete = False
    for i in range(1, l):
        if string[i] == string[i-1]:
            repete = True
            break
    if repete:
        print(1)
    else:
        print(l)
