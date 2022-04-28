# studentID1 = "19520250"
# studentID2 = "19521671"

# v5 = str(user_input)

s = "0250-1671" # username (studentID1 + "-" + studentID2)

v7 = "&5p~D" 

v4 = "5071&5p~D" # s[2:4] + s[7:9] + v7

v2 = 8 # len(studentID1)

# (s[i] + v4[i]) / 2 != v5[i] ? 

username = s # s
key = v4 # v4

password = ""

for i in range(9):
    password += chr((ord(username[i]) + ord(key[i])) // 2)

print(password)