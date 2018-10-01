def sumThreeSmallest(input):
    a, b, c = [float('inf')] * 3

    for i in input:
        if i < a:
            a, b, c = i, a, b
        elif a <= i < b:
            b, c = i, b
        elif b <= i < c:
            c = i

    ret = 0
    if a < float('inf'):
        ret += a
    if b < float('inf'):
        ret += b
    if c < float('inf'):
        ret += c

    return ret
