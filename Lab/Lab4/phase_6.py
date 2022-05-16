nodeArray =  [0x124, 0x399, 0x22c, 0x0ed, 0x1c1, 0x15d]

sortedArray = nodeArray.copy()
sortedArray.sort() # [237, 292, 349, 449, 556, 921]

# Print index of new value in origin array (nodeArray)
resultIndex = [(nodeArray.index(sortedArray[i]) + 1) for i in range(6)]

print(resultIndex)


