



You have a pre-compiled library which references the strtok function.
There is no source code for this library.

$ nm lib.a | grep strtok
      U _strtok

Your target system uses a RTOS and you have multiple threads which 
make calls into the library.

   a) Why might this be a problem?
   b) Can you think of a solution?



answer

a) strtok is not thread safe api and this will cause problem when multiple 
thread make a call to this function.

b) It is better to avoid using the library using strtok use the version 
which supports the multithread version. If this is not possible we have to use 
the call trace to find which api are calling this function and add semaphores 
to control multi thread issue


