import re

COMBINATIONS = {
    'A': (('A', 'A'), ('A', 'O')),
    'B': (('B', 'B'), ('B', 'O')),
    'AB': (('A', 'B'), ),
    'O': (('O', 'O'), )
}

R_COMBINATIONS = {
    'AA': 'A',
    'AB': 'AB',
    'AO': 'A',
    'BB': 'B',
    'BO': 'B',
    'OO': 'O',
}

A_COMBINATIONS = {
    'A': set(('AA', 'AO')),
    'B': set(('BB', 'BO')),
    'AB': set(('AB',)),
    'O': set(('OO',))
}


def sort(x):
    if x == 'O':
        return 1
    elif x == 'AB':
        return 2
    elif x == 'B':
        return 3
    elif x == 'A':
        return 4


def get_child_blood_types(p1, p2):
    rh = ['-', '+']
    if p1[-1] == '-' and p2[-1] == '-':
        rh = ['-']

    p1 = COMBINATIONS[p1[:-1]]
    p2 = COMBINATIONS[p2[:-1]]

    abo = set()
    for p11, p12 in p1:
        for p21, p22 in p2:
            abo.add(R_COMBINATIONS[''.join(sorted([p11, p21]))])
            abo.add(R_COMBINATIONS[''.join(sorted([p11, p22]))])
            abo.add(R_COMBINATIONS[''.join(sorted([p12, p21]))])
            abo.add(R_COMBINATIONS[''.join(sorted([p12, p22]))])

    return [a + r for a in sorted(abo, key=sort) for r in rh]


def get_parent_blood_types(p, ch):
    rh = ['-', '+']
    if p[-1] == '-' and ch[-1] == '+':
        rh = ['+']

    p = A_COMBINATIONS[p[:-1]]
    ch = A_COMBINATIONS[ch[:-1]]

    abo = set()
    for ct in ch:
        for pt in p:
            if ct[0] in pt:
                for k, vt in R_COMBINATIONS.items():
                    if ct[1] in k:
                        abo.add(vt)

            if ct[1] in pt:
                for k, vt in R_COMBINATIONS.items():
                    if ct[0] in k:
                        abo.add(vt)

    return [a + r for a in sorted(abo, key=sort) for r in rh]


i = 0
while True:
    types = input().strip()

    if not types:
        continue

    if types == 'E N D':
        break

    i += 1

    types = re.sub(r'[\s]+', " ", types).split(' ')

    v = None
    if types[2] == '?':
        v = get_child_blood_types(types[0], types[1])
    elif types[0] == '?' or types[1] == '?':
        v = get_parent_blood_types(
            types[1] if types[0] == '?' else types[0], types[2])

    r = 'Case %s:' % i

    for t in types:
        if t == '?':
            if v:
                r += ' %s' % v[0] if len(v) == 1 else ' {%s}' % ', '.join(v)
            else:
                r += ' IMPOSSIBLE'
        else:
            r += ' %s' % t

    print(r)
