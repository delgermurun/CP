DAYS_OF_MONTH = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
LEAP_DAYS_OF_MONTH = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def is_leap_year(year):
    return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)


def year_to_day(year):
    return year * 365 + int(year / 4) - int(year / 100) + int(year / 400)


def month_to_day(month, year):
    d = 0
    for m in range(month):
        d += DAYS_OF_MONTH[m]

    if month > 1 and is_leap_year(year):
        d += 1

    return d


def year_from_day(day):
    y = 1
    size = 365

    while day > size:
        y += 1
        day -= size
        size = 366 if is_leap_year(y) else 365

    return y, day


def month_from_day(day, year):
    m = 0
    days = LEAP_DAYS_OF_MONTH if is_leap_year(year) else DAYS_OF_MONTH

    while day > days[m]:
        day -= days[m]
        m += 1

    return m + 1, day


def solve(inp):
    day_forward, day, month, year = (int(ii) for ii in inp.split(' '))

    day += year_to_day(year - 1)
    day += month_to_day(month - 1, year)
    day += day_forward

    year, day = year_from_day(day)
    month, day = month_from_day(day, year)

    print(day, month, year)


while True:
    i = input()
    if i == '0 0 0 0':
        break

    solve(i)
