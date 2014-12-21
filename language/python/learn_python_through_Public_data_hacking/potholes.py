
import csv 

f = open('potholes.csv')
reader = csv.reader(f)
header = reader.next()

print header 

column = 'NUMBER OF POTHOLES FILLED ON BLOCK'
pot_indx = header.index(column)

column = 'STREET ADDRESS'
block_indx = header.index(column)

potholes = {}

for dat in reader:
    strr = dat[pot_indx]
    if strr.isdigit():
        val = float(strr)
    else:
        val = 0
    potholes[dat[block_indx]] = int(val)

tmp = potholes
Max = 0
start = {}
end = {}

for rl in potholes:
    for ll in temp:
        val = potholes[rl] - temp[ll]
        if val > Max:
            start = {rl:potholes[rl]}
            end   = {ll:temp[ll]}


