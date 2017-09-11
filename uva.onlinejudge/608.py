n = int(input())

for j in range(n):
    w = []

    for i in range(3):
        d = input()
        w.append(d.split(' '))

    for ch in [chr(c) for c in range(ord('A'), ord('L') + 1)]:
        not_fake = False

        for i in range(3):
            if w[i][2] != 'even' and ch not in w[i][0] and ch not in w[i][1]:
                not_fake = True
                break

            if w[i][2] == 'even' and (ch in w[i][0] or ch in w[i][1]):
                not_fake = True
                break

        if not_fake:
            continue

        for i in range(3):
            if w[i][2] == 'up' and ch in w[i][1]:
                break

            if w[i][2] == 'down' and ch in w[i][0]:
                break
        else:
            print(ch, 'is the counterfeit coin and it is heavy.')
            break

        for i in range(3):
            if w[i][2] == 'down' and ch in w[i][1]:
                break

            if w[i][2] == 'up' and ch in w[i][0]:
                break
        else:
            print(ch, 'is the counterfeit coin and it is light.')
            break
    else:
        print(ch, 'can not find')
