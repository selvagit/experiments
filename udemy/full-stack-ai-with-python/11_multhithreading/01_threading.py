import threading
import time

def take_orders():
    for i in range(5):
        print(f"Taking order {i}")
        time.sleep(1)  # Simulate time taken to take an order

def brew_chai():
    for i in range(5):
        print(f"Brewing chai {i}")
        time.sleep(2)  # Simulate time taken to brew chai

#create threads
order_thread = threading.Thread(target=take_orders)
brew_thread = threading.Thread(target=brew_chai)

order_thread.start()
brew_thread.start()

if __name__ == "__main__":  
    order_thread.join()
    brew_thread.join()
    print(f"All orders taken and chai brewed.") 