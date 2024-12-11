A = [(3,4,5),
     (2,5,7)]
# prob 1
def printMatrix(A, starting_index, rows, columns):
    row,col = starting_index
    for i in range(row, row+rows):
        for j in range(col, col+columns):
            print(A[i][j], end=' ')
        print()
        
#Prob 2
def MatAdd(A, B):
    rows, cols = len(A), len(A[0])
    C = [[0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        for j in range(cols):
            C[i][j] = A[i][j] + B[i][j]
    return C
    
# Prob 3
def MatAddPartial(A, B, start, size):
    row, col = start
    C = [[0 for _ in range(size)] for _ in range(size)]
    for i in range(size):
        for j in range(size):
            C[i][j] = A[row+i][col+j] + B[row+i][col+j]
    return C

#Prob 4
def MatMul(A, B):
    rows_A, cols_A = len(A), len(A[0])
    rows_B, cols_B = len(B), len(B[0])
    
    C = [[0 for _ in range(cols_B)] for _ in range(rows_A)]
    
    for i in range(rows_A):
        for j in range(cols_B):
            for k in range(cols_A):
                C[i][j] += A[i][k] * B[k][j]    
    return C

