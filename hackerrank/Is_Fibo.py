MAX_N = 10**10

if __name__ == '__main__':
    fibonacci = [0, 1]

    while fibonacci[-1] < MAX_N:
        fibonacci.append(fibonacci[-1] + fibonacci[-2])

    T = int(raw_input())

    for _ in range(T):
        N = int(raw_input())
        if N in fibonacci:
            print 'IsFibo'
        else:
            print 'IsNotFibo'

