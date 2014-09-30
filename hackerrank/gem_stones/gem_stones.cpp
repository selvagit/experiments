#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <fstream>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    unsigned int num_of_rocks = 0;
    std::cin >> num_of_rocks;

    std::string *test = new std::string[num_of_rocks];
    assert(test != NULL);

    for (unsigned int i = 0; i < num_of_rocks; i++){
        std::cin >> test[i];
    }

    unsigned int i,j,k;

    /* find the duplicate entries and remove them */
    for ( i = 0 ; i < num_of_rocks; i++){
        for( j = 0; j < test[i].length(); j++ ){
            for( k = j+1; k < test[i].length(); k++ ){
                if(test[i][j] == test[i][k]){
                    test[i].erase(test[i].begin()+k);
                    k--;
                }
            }
        }
    }

    //for ( i = 0 ; i < num_of_rocks ; i++){
    //    std::cout << test[i] << std::endl;
    //}

    std::string alpha_set = "abcdefghijklmnopqrstuvwxyz";
    unsigned int *gem_count = new unsigned int[alpha_set.length()];      

    for (unsigned int i = 0 ; i < num_of_rocks; i++){
        for (unsigned int j = 0; j < test[i].length(); j++ ){
            for (unsigned int k = 0 ; k < alpha_set.length(); k++ ){
                if ( test[i][j] == alpha_set[k] ){
                    gem_count[k]++;
                }
            }
        }
    }

    int num_of_gems = 0;
    for (unsigned int i = 0; i < alpha_set.length(); i++ ) {
        if( gem_count[i] == num_of_rocks){
            //std::cout << alpha_set[i] << std::endl;
            num_of_gems++;
        }
    }

    //std::cout << "number of gems = " << num_of_gems << std::endl;
    std::cout << num_of_gems << std::endl;

    delete[] gem_count;
    delete[] test;

    return 0;
}
