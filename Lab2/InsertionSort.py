import time
from Funcs import RandomArray
def InsertionSort(array,p,q):
    for i in range (p + 1 ,q):
        key = array[i]
        j = i - 1
        while j  >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j = j - 1
        array[j + 1] = key
    return array 
starttime = time.time() 
arr = RandomArray(10)
result = InsertionSort(arr,1,10)
endtime = time.time()
runtime = endtime - starttime
print (result)
print("Runtime in Seconds is: ", runtime)