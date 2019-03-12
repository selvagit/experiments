from random import randint

a = []

for i in range(3):
    a.append(randint(1,100))

print(a)

temp = a.pop()
print ("len of a "+str(len(a))+"\n")

avg = temp
for i in a:
    avg = (avg + i)/2.0
    
print(str(avg)+"\n")

a.append(temp)
print (sum(a)/float(len(a)))

