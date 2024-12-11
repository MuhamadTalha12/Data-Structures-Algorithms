import time

def append_and_track_time():
    num_list = []
    for z in range(1, 101):
        start_time = time.time() 
        num_list.append(z)
        end_time = time.time()
        runtime = end_time - start_time
        print(f"Numbers list after adding {z} elements: {num_list}")
    print(f"Runtime after adding {z} elements is: {runtime}")

# Driver
append_and_track_time()
