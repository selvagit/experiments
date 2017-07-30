
def f(m,n):
     ans = 1
     while (m - n >= 0):
       (ans,m) = (ans*2,m-n)
     return(ans)
