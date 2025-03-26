def add(matA, matB):
    ans = []
    for i in range(len(matA)):
        rowA = matA[i]
        rowB = matB[i]
        rowAns = []
        for j in range(len(rowA)):
            rowAns.append(rowA[j] + rowB[j])
        ans.append(rowAns)
    return ans


def diff(matA, matB):
    ans = []
    for i in range(len(matA)):
        rowA = matA[i]
        rowB = matB[i]
        rowAns = []
        for j in range(len(rowA)):
            rowAns.append(rowA[j] - rowB[j])
        ans.append(rowAns)
    return ans


def multiply(matA, matB):
    ans = [[0 for _ in range(len(matB[0]))] for _ in range(len(matA))]
    for i in range(len(matA)):
        for j in range(len(matB[0])):
            for k in range(len(matB)):
                ans[i][j] += matA[i][k] * matB[k][j]
    return ans


matA = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
matB = [
    [2, 3, 4],
    [5, 6, 7],
    [8, 9, 1]
]

print(multiply(matB, matA))
print(add(matA, matB))
print(diff(matA, matB))
