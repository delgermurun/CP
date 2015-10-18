h = input();
m = input();

dic = {
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    10: 'ten',
    11: 'eleven',
    12: 'twelwe',
    13: 'thirteen',
    14: 'fourteen',
    15: 'fifteen',
    16: 'sixteen',
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'thirty',
    40: 'forty',
    50: 'fifty'
}

s = '';
if m == 0:
    s = dic[h] + ' o\' clock'
elif m == 1:
    s = dic[m] + ' minute past ' + dic[h]
elif m < 15:
    s = dic[m] + ' minutes past ' + dic[h]
elif m == 15:
    s = 'quarter past ' + dic[h]
elif m < 21:
    s = dic[m] + ' minutes past ' + dic[h]
elif m < 30:
    s = dic[(m/10)*10] + ' ' + dic[m%10] + ' minutes past ' + dic[h]
elif m == 30:
    s = 'half past ' + dic[h]
elif m < 41:
    m = 60 - m
    h += 1
    if h > 12:
        h = h % 12

    s = dic[(m/10)*10] + ' ' + dic[m%10] + ' minutes to ' + dic[h]
elif m < 45:
    m = 60 - m
    h += 1
    if h > 12:
        h = h % 12

    s = dic[m] + ' minutes to ' + dic[h]
elif m == 45:
    h += 1
    if h > 12:
        h = h % 12

    s = 'quarter to ' + dic[h]
elif m == 59:
    h += 1
    if h > 12:
        h = h % 12

    s = 'one minute to ' + dic[h]
else:
    m = 60 - m
    h += 1
    if h > 12:
        h = h % 12

    s = dic[m] + ' minutes to ' + dic[h]

print s
