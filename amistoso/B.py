for k in range(int(input())):
    val = True
    vogais = "aeiou"
    s = input()
    if len(s) < 3: print("NO")
    else:
        fst = s[0] in vogais
        
        for i in range(1, len(s)):
            if fst and s[i] not in vogais: 
                fst = False
            elif not fst and s[i] in  vogais:
                fst = True
            else:
                val = False
                break
            
        if val: print("YES")
        else: print("NO")