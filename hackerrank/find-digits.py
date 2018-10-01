T = int(raw_input())

for _ in range(T):
    n = int(raw_input())
    res = 0
    for ni in str(n):
        if int(ni) != 0 and n % int(ni) == 0:
            res += 1
    print(res)
