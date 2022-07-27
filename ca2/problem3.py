def solve(sena):
    if 'R' not in sena or 'D' not in sena:
        return sena
    new_sena = []
    silent_r = 0
    silent_d = 0
    for i in range(len(sena)):
        if sena[i] == 'R':
            if silent_r == 0:
                silent_d += 1
                new_sena.append(sena[i])
            else:
                silent_r -= 1
        elif sena[i] == 'D':
            if silent_d == 0:
                silent_r += 1
                new_sena.append(sena[i])
            else:
                silent_d -= 1
    if silent_d != 0 or silent_r != 0:
        for i in range(len(new_sena)):
            if silent_d > 0 and 'D' in new_sena:
                new_sena.remove('D')
                silent_d -= 1
            elif silent_r > 0 and 'R' in new_sena:
                new_sena.remove('R')
                silent_r -= 1
            else:
                break
    return solve(new_sena)


dota_str = input()
x = solve(dota_str)
if x[-1] == 'R':
    print('Radiant')
else:
    print('Dire')
