// this file is meant for testing the algorithms by comparing two directory
// for finding the duplicate files and measure time taken by each algorithm to 
// search the directory 
//
// Steps to done
// 1) Open a directory
// 2) find all the files and directory 
// 3) Create a database of all the files found 
// 4) for every new file found compare it with the existing data base and report if the file already exist
// 5) use different search algorithm to search 
// 6) use arguement list option library to add command line option 
// 7) OpenMPI / OpenCL can used for scaling 


#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void traverse_dir(char *dir_name)
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct stat info;
    
    if ((dir = opendir(dir_name)) == NULL){
        std::cout << " dir open error " << dir_name << std::endl;
    } else {
        entry = readdir(dir);
        while(entry != NULL){
            std::cout << "<->" << entry->d_name << std::endl;
            entry = readdir(dir);
        }
    }
    return ;
}

int main ( int argv , char * arg[])
{
    traverse_dir("./"); 
    return 0;
}







