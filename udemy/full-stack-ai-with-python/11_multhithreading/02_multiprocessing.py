from multiprocessing import  Process
import time

def brew_chai(name):
    print(f"Process {name}: Starting to brew chai")
    time.sleep(4)  # Simulate time taken to brew chai
    print(f"Process {name}: Finished brewing chai")

if __name__ == "__main__":  
    chai_makers = [
        Process(target=brew_chai, args=(f"ChaiMaker-{i}",)) 
        for i in range(5)
    ]

    # Start all processes
    for maker in chai_makers:
        maker.start()

    # Wait for all processes to complete
    for maker in chai_makers:
        maker.join()

    print("All chai brewed.")
