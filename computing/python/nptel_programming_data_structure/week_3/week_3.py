
def ascending(lst):

    if len(lst) == 0:
        return True;

    if len(lst) == 1:
        return True;

    status = True
    for i in range(1,len(lst)):
       if(lst[i] < lst[i-1]):
           status = False
           break;

    return status
        

def valley(lst):
    
    if len(lst) == 1:
        return False

    sign = []
    for i in range(1,len(lst)):
        if lst[i-1] < lst[i]:
            sign.append(1)
        elif lst[i-1] == lst[i]:
            sign.append(0)
        else:
            sign.append(-1)

    for i in range(len(sign)):
        if sign[i] == 0:
            return False

    change = 0
    for i in range(1,len(sign)):
       if sign[i-1] != sign[i]:
            if change == 1:
                return False
            change = 1

    return True



def transpose(mat):
    
    tmat = [[]]
    m = len(mat)
    n = len(mat[0])

    temp = []
    for i in range(n):
        for j in range(m):
           temp.append(mat[j][i])
        tmat.append(temp)
        temp = []

    return tmat[1:]











            
