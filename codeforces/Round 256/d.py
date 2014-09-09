n, m, k = map(int, raw_input().split(' '))
res = {}

for i in range(1, n + 1):
    for j in range(1, m + 1):
        p = i * j
        if p not in res:
            res[p] = 0
        res[p] += 1

t = 0
for i in sorted(res.keys()):
    if t + res[i] >= k:
        print i
        break
    t += res[i]
