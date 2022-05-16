# ==================== PHASE 5 ====================

array_2705 = [2, 10, 6, 1, 12, 16, 9, 3, 4, 7, 14, 5, 11, 8, 15, 13]
input = '000000'
while(len(input) == 6):
    v3 = 0
    for i in range(0, 6):
        res = array_2705[int(input[i]) & 0xF]
        v3 += res
    if v3 == 48:
        print(input)

    input = str(int(input) + 1)
    if(len(input) != 6):
        input = str(0)*(6 - len(input)) + input