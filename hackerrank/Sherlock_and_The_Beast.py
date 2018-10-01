T = int(raw_input())
for i in range(T):
    n = int(raw_input())
    upper = 10**n - 1
    lower = 10**(n - 1)
    print n, upper, lower
    found = False
    j = upper
    while j >= lower:
        n = str(j)
        threes = n.count('3')
        fives = n.count('5')
        if threes + fives == len(n) and threes % 5 == 0 and fives % 3 == 0:
            found = True
            print n
            break
        j -= 1
    if not found:
        print -1
