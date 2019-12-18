
import re


f_inp = open("csort.txt", "r")
f_task = open("task_load.txt", "w")
f_heap = open("heap.txt", "w")

for line in f_inp:
    check = re.search('Cpu_stat|Task_stat',line)
    if check:
        f_task.write(line)

    check = re.search('Heap_stat',line)
    if check:
        f_heap.write(line)

f_inp.close()
f_task.close()
f_heap.close()

core = ["C-0", "C-1" , "C-2" , "C-3", "C-4", "C-5","C-6", "C-7"]

def extract_mfw_info (core_name,dump_file_name):

    f_task = open(dump_file_name, "r")
    f_C = open(core_name+".txt", "w")

    for line in f_task:
        check = re.search(core_name,line)
        if check:
            f_C.write(line)

    f_C = open(core_name+".txt", "r")
    f_mfw = open(core_name+"_mfw.txt", "w")

    for line in f_C:
        check = re.search("MFW",line)
        if check:
            f_mfw.write(line)
            d = line.split()
            print(d[7],d[10],d[13])

for core_name in core:
    extract_mfw_info (core_name,"task_load.txt")
