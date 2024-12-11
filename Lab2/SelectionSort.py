import time
import csv
from Funcs import RandomArray
def SelectionSort(array,start,end):
    n = len(array)
    for i in range (start,end):
        minidx = i
        for j in range (i+1, end+1):
            if array[j] < array[minidx]:
                minidx = j
        array[i], array[minidx] = array[minidx], array[i]
    return array
# starttime = time.time()
# arr = RandomArray(10)
# res = SelectionSort(arr,0,len(arr)-1)
# endtime = time.time()
# runtime = endtime - starttime
# print ("The runtime in seconds is: ", runtime)

# with open('SelectionSort.csv', mode='w', newline='\n') as file:
#     writer = csv.writer(file)
#     for i in arr:
#         writer.writerow([i])

def Selectionsort(Arr):
    n = len(Arr)
    for i in range(n):
        minidx = i
        for j in range(i+1,n):
            if Arr[j] < Arr[minidx]:
                minidx = j
        Arr[i],Arr[minidx] = Arr[minidx],Arr[i]
    return Arr