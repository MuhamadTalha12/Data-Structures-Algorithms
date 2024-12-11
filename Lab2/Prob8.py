from InsertionSort import InsertionSort
from MergeSort import MergeSort,Merge
from Funcs import RandomArray
import csv

def read_values(filename):
    with open(filename, 'r') as file:
        return [int(line.strip()) for line in file]

def write_csv(filename, data):
    """Write data to a CSV file."""
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['N', 'InsertionSort Time', 'SelectionSort Time'])
        for row in data:
            writer.writerow(row)

def measure_runtime(func, data, start, end):
    import time
    start_time = time.time()
    func(data, start, end)
    end_time = time.time()
    return (end_time - start_time)

def RandomArray(size):
    newArray = []
    for i in range(size):
        randomNumber = random.randint(0, 30000)
        newArray.append(randomNumber)
    return newArray
def main():
    n_values = read_values('Nvalues.txt')
    results = []
    for n in n_values:
        test_data = RandomArray(n)
        insertion_sort_time = measure_runtime(InsertionSort, test_data.copy(), 0, n - 1)
        merge_sort_time = measure_runtime(MergeSort, test_data.copy(), 0 , n - 1)
        results.append([n, f"{insertion_sort_time:.2f}", f"{merge_sort_time:.2f}"])
    write_csv('RunTime.csv', results)
if __name__ == '__main__':
    main()