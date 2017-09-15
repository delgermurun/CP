while True:
    r = input()
    if r == '0:00':
        break

    h, m = (int(rr) for rr in r.split(':'))

    a = abs(30 * h - m * 6 + 0.5 * m)

    if a > 180:
        a = 360 - a

    print('%.3f' % a)
