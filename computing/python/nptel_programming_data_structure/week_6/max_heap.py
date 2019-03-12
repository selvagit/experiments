


def max_heap (li) :
    
    for i in range (1:len(li)):
        if li[i] > li[i-1]:
            li[i] , li [i-1] = li[i],li[i-1] 
            
    
