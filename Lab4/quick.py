def quickSort(A):
    if(len(A) <=1):
        return A
    
    q = Partition(A)
    left = quickSort(A[0:q])
    right = quickSort(A[q+1:])
    return left + [A[q]] + right
def Partition(A):
    x = A[-1]
    i=0
    j=0
    while(i<len(A)-1):
        if (A[i] <= x):
            A[j],A[i] = A[i],A[j]
            j = j + 1
            i = i + 1
        else:
            i = i+1
    A[j],A[-1] = A[-1],A[j]
    return j     
    
a = [5,1,23,43,12]    
print(quickSort(a))    