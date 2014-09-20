n = int(raw_input())

if n < 4:
    print 'NO'
else:
    print 'YES'
    while n > 5:
        print n, '-', n - 1, '=', 1
        print '1 * 1 = 1'
        n -= 2

    if n == 4:
        print '4 * 3 = 12'
        print '2 * 1 = 2'
        print '12 * 2 = 24'
    elif n == 5:
        print '5 + 4 = 9'
        print '9 + 3 = 12'
        print '12 * 2 = 24'
        print '24 * 1 = 24'
