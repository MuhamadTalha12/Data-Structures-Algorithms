Array= [-5, -10, 0, -3, 8, 5, -1, 10]
Array2= [110, 45, 65,50, 90, 602, 24, 2, 66]
Array3 = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434]

def CountingSort(A):
    if not A:
        return []
    minValue = min(A)
    maxValue = max(A)
    count = [0] * (maxValue - minValue + 1)
    result = [0] * len(A)

    for i in range(0,len(A)):
        count[A[i] - minValue] += 1

    for i in range(1, len(count)):
        count[i] += count[i - 1]

    for idx in range(len(A) - 1, -1, -1):
        num = A[idx]
        count[num - minValue] -= 1
        result[count[A[idx] - minValue]] = num

    return result

# SortedArray = CountingSort(Array)
# print(SortedArray)  

def CountingSortRadix(A, digitpos):
    k = 10 
    count = [0] * k
    result = [0] * len(A)

    for num in A:
        digit = (num // digitpos) % 10
        count[digit] += 1
    
    for i in range(1,len(count)):
        count[i] += count [i - 1]

    for i in range(len(A) - 1, -1, -1):
        num = A[i]
        digit = (num // digitpos) % 10
        count[digit] -= 1
        result[count[digit]] = num
    return result

def RadixSort(A):
    if len(A) == 0:
        return A
    
    MaxValue = max(A)

    digitpos = 1
    while MaxValue // digitpos > 0:
        A = CountingSortRadix(A, digitpos)
        digitpos *= 10
    return A

# print("Original Array:", Array2)
# SortedArray = RadixSort(Array2)   
# print("RadxSort:", SortedArray)


#Bucket Sort
# def InsertionSortBucket(bucket):
#     n = len(bucket)
#     for i in range(1, n):
#         k = bucket[i]
#         j = i - 1
#         while j >= 0 and k > bucket[j]:
#             bucket[j + 1] = bucket[j]
#             j -= 1
#         bucket[j + 1] = k

# def BucketSort(A):
#     n = len(A)
#     if n <= 0:
#         return A

#     arrBucket = [[] for _ in range(n)]

#     for value in A:
#         index = min(n - 1, int(value * n)) 
#         arrBucket[index].append(value)

#     for i in range(n):
#         InsertionSortBucket(arrBucket[i])


#     arrSorted = []
#     for bucket in arrBucket:
#         arrSorted.extend(bucket)

#     return arrSorted

def insertion_sort(bucket):
    for i in range(1, len(bucket)):
        key = bucket[i]
        j = i - 1
        while j >= 0 and bucket[j] > key:
            bucket[j + 1] = bucket[j]
            j -= 1
        bucket[j + 1] = key

def bucket_sort(arr):
    if len(arr) == 0:
        return arr

    max_value = max(arr)
    min_value = min(arr)
    bucket_count = (max_value - min_value) // len(arr) + 1  
    buckets = [[] for _ in range(bucket_count)]  

    for num in arr:
        index = (num - min_value) // len(arr)
        buckets[index].append(num)  

    for bucket in buckets:
        insertion_sort(bucket)

    sorted_array = []
    for bucket in buckets:
        sorted_array.extend(bucket)  

    return sorted_array

# Example usage
arr = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.55, 0.21]
print("Original array:", arr)
sorted_arr = bucket_sort(arr)
print("Sorted array:", sorted_arr)

# print("Original Array:", Array3)    
# SortedArray = BucketSort(Array3)
# print("BucketSort:", SortedArray)