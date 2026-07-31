t = int(input())
for k in range(t):
    string = input()
    for letter in string[::-1]:
        if letter == 'p':
            print('q', end='')
        elif letter == 'q':
            print('p', end='')
        else:
            print('w', end='')
    print()