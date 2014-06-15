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
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void traverse_dir(std::string &parent_dir_name)
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct stat info;

    if ((dir = opendir(parent_dir_name.c_str())) == NULL){
        std::cout << " dir open error " << parent_dir_name << std::endl;
    } else {
        while((entry = readdir(dir))!=NULL){
            if(stat(entry->d_name,&info) == 0){
                if(S_ISDIR(info.st_mode)){
                    std::string dir_name = parent_dir_name;
                    //dir_name = dir_name + "/";
                    std::cout << "Dir:" << dir_name << std::endl;
                }else{
                    std::cout << "File:" << entry->d_name << std::endl;
                }
            }
        }
    }
    closedir(dir);
    return ;
}

int main ( int argc , char *argv[])
{
    std::string dir_name;
    if(argc>1){
        dir_name.assign(argv[1]);
        traverse_dir(dir_name); 
    }else{
        std::cout << "enter a dir path, going for current dir"<< std::endl;
        dir_name.assign("./");
        traverse_dir(dir_name); 
    }
    return 0;
}







