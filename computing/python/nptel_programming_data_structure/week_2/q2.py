

x = ['a',42,'b',377]
   w = x[1:]
   y = x
   u = w
   w = w[0:]
   w[0] = 53
   x[1] = 47

#correct answer is x[1] == 47, y[1] == 47, w[0] == 53, u[0] == 42 


