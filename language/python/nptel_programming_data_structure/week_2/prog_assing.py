
def perfect(n):
    factor = []
    for i in range(1,n):
        if ( (n%i) == 0):
            factor.append(i)
    
    sum = 0
    for i in factor:
        sum = sum + i 

    if (sum == n):
        return("True")
    else:
        return("False")


def depth(l):
    d = 0
    dmax = 0

    for i in l:
        if ( i == '('):
            d = d + 1
            if ( d > dmax ):
                dmax = d
        if ( i == ')'):
            d = d - 1

    return(dmax)

def sumsquares(l):
    
    sum_number = [] 

    for i in l:
        if (i==1):
            sum_number.append(i)

        for j in range(1,i):
            if ((j*j) == i):
                sum_number.append(i) 
        
    return(sum(sum_number)) 
