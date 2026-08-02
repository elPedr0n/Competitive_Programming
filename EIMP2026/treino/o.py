s = [int(k) for k in input().split()]
while True:
    if not s[0] and not s[1]: break
    x1, x2, out = 1, 2, 0
    if s[0] <= 1 and s[1] >= 1: out += 1
    while x2 <= s[1]:
        if x2 >= s[0] and x2 <= s[1]: out += 1
        x1, x2 = x2, x1 + x2
    print(out)
    s = [int(k) for k in input().split()]