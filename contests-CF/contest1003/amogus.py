t = int(input()) 
for i in range(t):
    string = input()
    l = len(string)
    if l == 2:
        print("i")
    else:
        print(string[:l-2] + "i")