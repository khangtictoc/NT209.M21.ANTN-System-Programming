# ==================== PHASE 4 ====================

def func4(a1, a2, a3):
    v4 = (a3 - a2) / 2 + a2
    if v4 > a1:
        return func4(a1, a2, v4 - 1) + v4
    if v4 >= a1:
        return (a3 - a2) / 2 + a2
    return func4(a1, v4 + 1, a3) + v4

for v2 in range(15):
    print(str(func4(v2, 0, 14)) + " " + str(v2))