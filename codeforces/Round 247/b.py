raw_input()
v = raw_input().split(' ')
v = [int(vi) for vi in v]
s = sorted(v)
m = int(raw_input())
for _ in range(m):
    t, l, r = raw_input().split(' ')
    t = int(t)
    l = int(l)
    r = int(r)
    if t == 1:
        count = 0
        idx = l
        while idx <= r:
            count += v[idx - 1]
            idx += 1
        print count
    else:
        count = 0
        idx = l
        while idx <= r:
            count += s[idx - 1]
            idx += 1
        print count
