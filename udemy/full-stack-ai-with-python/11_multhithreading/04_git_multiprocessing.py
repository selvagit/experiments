from multiprocessing import Process
import time

def brew_chai():
    print(f"{Process.pid} started brewing")
    count = 0
    for _ in range (100_000_000):
        count += 1
    print(f"{Process.pid} finished brewing")


if __name__ == "__main__":
    process_1 = Process(target=brew_chai, name="Barista-1")
    process_2 = Process(target=brew_chai, name="Barista-2")

    start = time.time()
    process_1.start()
    process_2.start() 

    process_1.join()
    process_2.join() 

    end = time.time() 

    print(f"total time taken: {end-start:.2f}")