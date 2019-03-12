
x = [1,"abcd",2,"efgh",[3,4]]  # Statement 1
y = x[0:50]                    # Statement 2
z = y                          # Statement 3
w = x                          # Statement 4
x[1] = x[1][0:3] + 'd'         # Statement 5
y[2] = 4                       # Statement 6
z[0] = 0                       # Statement 7
x[1][1:2] = 'yzw'              # Statement 8
w[4][0] = 1000                 # Statement 9
a = (x[4][1] == 4)             # Statement 10
