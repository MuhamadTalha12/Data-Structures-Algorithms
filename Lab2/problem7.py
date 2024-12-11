import csv
import time
from InsertionSort import InsertionSort
from MergeSort import MergeSort,Merge
from HybridMerge import hybridMergeSort
from Bubble import BubbleSort
from SelectionSort import SelectionSort
from Funcs import RandomArray

def printHeader():
    with open('RunTime.csv', mode='w', newline='\n') as file:
        writer = csv.writer(file)
        for i in arr:
            writer.writerow(["Value of (n)","Insertion Sort","Merge Sort","Hybrid Merge Sort","Selection Sort","Bubble Sort"])

def FindInsertionSortTime(num):
    starttime = time.time()
    array = RandomArray(num)
    InsertionSort(array,0,num)
    endtime = time.time()
    runtime = endtime - starttime
    return runtime

def FindMergeSortTime(num):
    starttime = time.time()
    array = RandomArray(num)
    MergeSort(array,0,num)
    endtime = time.time()
    runtime = endtime - starttime
    return runtime

def FindHybridMergeSortTime(num):
    starttime = time.time()
    array = RandomArray(num)
    hybridMergeSort(array,0,num)
    endtime = time.time()
    runtime = endtime - starttime
    return runtime

def FindSelectionSortTime(num):
    starttime = time.time()
    array = RandomArray(num)
    SelectionSort(array,0,num)
    endtime = time.time()
    runtime = endtime - starttime
    return runtime

def FindBubbleSortTime(num):
    starttime = time.time()
    array = RandomArray(num)
    BubbleSort(array,0,num)
    endtime = time.time()
    runtime = endtime - starttime
    return runtime

def CsvFile(num):
    InsertionSort = FindInsertionSortTime(num)
    MergeSort = FindMergeSortTime(num)
    HybridMergeSort = FindHybridMergeSortTime(num)
    SelectionSort = FindSelectionSortTime(num)
    BubbleSort = FindBubbleSortTime(num)
    arr = [num, InsertionSort , MergeSort, HybridMergeSort, SelectionSort, BubbleSort]
    printHeader()
    
with open('NValues.txt', 'r') as file:
    line = file.readline()
    while line:
        CsvFile(int(line))
        line = file.readline()
    