from multiprocessing import Process, Queue 
import time 

def prepare_chai(queue):
    queue.put("Masala chai is ready")
    print(f"Done")

queue = Queue()

start = time.time()

processes = [Process(target=prepare_chai, args=(queue,)) for _ in range(1)]

[t.start() for t in processes]
[t.join() for t in processes]

end = time.time()

print(f"time taken {end-start:.02f} seconds")

print(queue.get())