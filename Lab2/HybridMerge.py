import time
import csv
from Funcs import RandomArray
from MergeSort import Merge,MergeSort
from Insertion import InsertionSort
def hybridMergeSort(arr, start, end):
    if (end - start + 1) <= 10:
        InsertionSort(arr, start, end)
    else:
        mid = (start + end) // 2
        hybridMergeSort(arr, start, mid)
        hybridMergeSort(arr, mid + 1, end)
        Merge(arr, start, mid, end)
starttime = time.time()
arr = RandomArray(100)
hybridMergeSort(arr, 0, len(arr) - 1)
endtime = time.time()
runtime = endtime - starttime
print("The Runtime in Seconds is: " , runtime)

with open('HybridMergeSort.csv', mode='w', newline='\n') as file:
    writer = csv.writer(file)
    for i in arr:
        writer.writerow([i])