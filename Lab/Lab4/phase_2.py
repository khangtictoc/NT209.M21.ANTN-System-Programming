print("Enter valid number (n >=6): ", end="")

num = int(input())
result = ""

if (num >=6):
    for i in range(0, num):
        result += str(2 ** i) + " "

print(result)