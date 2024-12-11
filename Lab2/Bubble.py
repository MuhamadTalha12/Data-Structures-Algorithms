import time
import csv
from Funcs import RandomArray
def BubbleSort(array,start,end):
    n = len(array)
    for i in range (end):
        for j in range (start,end-i):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array
starttime = time.time()
arr = RandomArray(10)
res = BubbleSort(arr,0,len(arr)-1)
endtime = time.time()
runtime = endtime - starttime
print ("The runtime in seconds is: ", runtime)

with open('BubbleSort.csv', mode='w', newline='\n') as file:
    writer = csv.writer(file)
    for i in arr:
        writer.writerow([i])
# def Bubblesort(Arr):
#     n = len(Arr)
#     for i in range(n):
#         for j in range(n-i-1):
#             if Arr[j+1] < Arr[j]:
#                 Arr[j],Arr[j+1] = Arr[j+1],Arr[j]
#     return Arr
# arr = [1,5,7,9,45,242]
# print(Bubblesort(arr))
