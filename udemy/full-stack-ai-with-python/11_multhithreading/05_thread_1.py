import threading 
import time

def boil_milt():
    print(f"Boiling milk")
    time.sleep(2)
    print(f"finished brewing")



def toast_bun():
    print(f"Toasting Bun")
    time.sleep(2)
    print(f"finished bun")


if __name__ == "__main__":
    t1 = threading.Thread(target=boil_milt, name="Barista-1")
    t2 = threading.Thread(target=toast_bun, name="Barista-2")

    start = time.time()
    t1.start()
    t2.start() 

    t1.join()
    t2.join() 

    end = time.time() 

    print(f"total time taken: {end-start:.2f}")
