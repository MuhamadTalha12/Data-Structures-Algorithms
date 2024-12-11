import time
import csv
from Funcs import RandomArray
def InsertionSort(array,start,end):
    for i in range (start + 1 ,end + 1):
        key = array[i]
        j = i - 1
        while j  >= 0 and array[j] > key:
            array[j + 1]  = array[j]
            j -= 1
        array[j + 1] = key
    return array 
starttime = time.time() 
arr = RandomArray(30000)
result = InsertionSort(arr,100,28000)
endtime = time.time()
runtime = endtime - starttime
print (result)
print("Runtime in Seconds is: ", runtime)

with open('InsertionSort.csv', mode='w', newline='\n') as file:
    writer = csv.writer(file)
    for i in arr:
        writer.writerow([i])