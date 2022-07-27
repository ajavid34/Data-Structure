def f(h, n, state):
    if h == 1:
        if n == 1:
            if state == 'l':
                return 1
            else:
                return 2
        elif n == 2:
            if state == 'l':
                return 2
            else:
                return 1
    if n > 2**(h - 1) and state == 'l':
        return 2**h + f(h - 1, n - 2**(h - 1), 'l')
    elif n > 2**(h - 1) and state == 'r':
        return 1 + f(h - 1, n - 2 ** (h - 1), 'l')
    elif n <= 2**(h - 1) and state == 'r':
        return 2**h + f(h - 1, n, 'r')
    else:
        return 1 + f(h - 1, n, 'r')


h, n = [int(x) for x in input().split()]
print(f(h, n, 'l'))
