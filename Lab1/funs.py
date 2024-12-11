# Problem // 1
# X = [22,2,1,7,11,13,5,2,9]
# def SearchA(Array , x):
#     searchedArray = []
#     for i in range(len(Array)):
#         if Array[i] == x:
#             searchedArray.append(i)
#     return searchedArray
# x = int(input("Enter a number: "))
# result = SearchA(X, x)
# print("Index :" , result)

#Problem // 2
# X = [22,2,1,7,11,13,5,2,9]
# X.sort()
# def SearchA(Array , x):
#      searchedArray = []
#      for i in range(len(Array)):
#         if Array[i] == x:
#             searchedArray.append(i)
#         elif Array[i] > x:
#             break
#      return searchedArray
# x = int(input("Enter a number: "))
# result = SearchA(X, x)
# print("Index :" , result)

#Problem // 3
# X = [3,4,7,8,0,1,23,-2,-5]
# def Minimum(Arr, starting, ending):
#     minimumidx = starting
#     for i in range(starting, ending + 1):
#         if Arr[i] < Arr[minimumidx]:
#             minimumidx = i
#     return minimumidx
# starting = int(input("StartingIndex: "))
# ending = int(input("EndingIndex: "))
# result = print(Minimum(X, starting, ending))
    
#Problem // 4
# Arr = [100,101,-5,-4,-3,0,4,1,35,1]

# def Sort4(Arr):
#     for i in range(len(Arr)):
#         for j in range(i+1, len(Arr)):
#             if Arr[i] > Arr[j]:
#                 Arr[i], Arr[j] = Arr[j], Arr[i]
#     return Arr
# print(Sort4(Arr))
    
#Problem // 5
# s = "University of Engineering and Technology Lahore"
# def StringReverse(str, starting, ending):
#     return (ending + 1 , starting, -1)
# starting = int(input("StartingIndex: "))
# ending = int(input("EndingIndex: "))
# result = print(StringReverse(s, starting, ending))

#Problem // 6
# def SumIterative(num):
#     sum = 0
#     while num > 0:
#         sum = sum + num % 10
#         num = num // 10
#     return sum
# def SumRecursive(num):
#     if num == 0:
#         return 0
#     else:
#         return num % 10 + SumRecursive(num // 10)

# input = int(input("Enter a number: "))
# print("Sum of digits is:", SumIterative(input))
# print("Sum of digits is:", SumRecursive(input))

#Problem // 7
# A = [
#     (1,13,13),
#     (5,11,6),
#     (4,4,9)
#     ]

# def RowWiseSum(Mat):
#     array = []
#     for i in Mat:
#         array.append(sum(i))
#     return array
# def ColumnWiseSum(Mat):
#     array = []
#     for i in range(len(Mat[0])):
#         sum = 0
#         for j in range(len(Mat)):
#             sum += Mat[j][i]
#         array.append(sum)
#     return array
# print("Row-Wise: ", RowWiseSum(A))
# print("Column-Wise: " , ColumnWiseSum(A))


#Problem // 8
# A = [0,3,4,10,11] 
# B = [1,8,13,24] 

# def SortedMerge(Arr1, Arr2):
#     n = 0
#     result = []
#     for i in range (len(Arr1)):
#         while(n < len(Arr2)):
#             if(Arr2[n] < Arr1[i]):
#                 result.append(Arr2[n])
#                 n = n+1
#             else:
#                  break
#         result.append(Arr1[i])
#     while(n < len(Arr2)):
#         result.append(Arr2[n])
#         n = n+1
#     return result

# print(SortedMerge(A,B))
    

#Problem // 9
# Str = input("Input :")
# def PalindromRecursive(str):
#     if (len(str)) < 2:
#         return True
#     if str[0] == str[-1]:
#         return PalindromRecursive(str[1:-1])
#     else:
#         return False
# if PalindromRecursive(Str):
#     print("Output: " , "Palindrome")
# else:
#     print("Output: " , "Not Palindrome")

#Problem 10
# A = [10, -1, 9 , 20, -3, -8, 22, 9, 7]

# def Sort10(Arr):
#     positive = [x for x in Arr if x >= 0]
#     negative = [x for x in Arr if x < 0]
#     positive.sort()
#     negative.sort()
#     return negative + positive
# print(Sort10(A))