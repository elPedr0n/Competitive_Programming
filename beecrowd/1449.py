for k in range(int(input())):
    mn = [int(i) for i in input().split()]
    m, n = mn[0], mn[1]
    dict = {}
    anterior = ''
    for i in range(2 * m):
        st = input()
        if i % 2 == 0:
            dict[st] = '0'
            anterior = st
        else:
            dict[anterior] = st

    for i in range(n):
        st = input().split()
        for j in range(len(st)):
            word = st[j]
            if word in dict:
                print(dict[word], end='')
            else:
                print(word, end='')
            if j != len(st) - 1:
                print(' ', end='')
        print()
    print()