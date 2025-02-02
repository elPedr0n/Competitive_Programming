dna = input()
maxi, act = 1, 1
for i in range(1, len(dna)):
    if dna[i] == dna[i-1]:
        act += 1
    else: 
        act = 1    
        
    if maxi < act:
        maxi = act
print(maxi)        