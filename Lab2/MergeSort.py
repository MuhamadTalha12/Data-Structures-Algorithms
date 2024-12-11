import time 
import csv
import random
def MergeSort(array,start,end):
    if start < end:
        mid = (start + end) // 2 
        MergeSort(array,start,mid)
        MergeSort(array,mid+1,end)
        Merge(array,start,mid,end)
    return array
def Merge(array,p,q,r):
    leftArray = array[p:q+1]
    rightArray = array[q+1:r+1]
    
    i = j = 0
    k = p
    while i < len(leftArray) and j < len(rightArray):
        if leftArray[i] <= rightArray[j]:
            array[k] = leftArray[i]
            i += 1
        else:
            array[k] = rightArray[j]
            j += 1
        k = k + 1
    while i < len(leftArray):
        array[k] = leftArray[i]
        i+=1
        k+=1
    while j < len(rightArray):
        array[k] = rightArray[j]
        j+=1
        k+=1
        
startTime = time.time()
array1 = [random.randint(0,10)for i in range(10)]
ans = MergeSort(array1,0,len(array1)-1)
endTime = time.time()
runtime = endTime- startTime
print("The runtime in seconds is ", runtime)

with open('MergeSort.csv', mode='w', newline='\n') as file:
    writer = csv.writer(file)
    for i in array1:
        writer.writerow([i])