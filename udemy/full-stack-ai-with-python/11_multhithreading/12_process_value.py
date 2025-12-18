from multiprocessing import Process, Value 
import time 

def prepare_chai(queue):
    queue.put("Masala chai is ready")
    print(f"Done")

def increment(counter):
    for _ in range(100000):
        with counter.get_lock():
            counter.value += 1

counter = Value('i',0)

start = time.time()

processes = [Process(target=increment, args=(counter,)) for _ in range(4)]

[t.start() for t in processes]
[t.join() for t in processes]

end = time.time()

print(f"time taken {end-start:.02f} seconds")

print("Final counter:", counter.value)