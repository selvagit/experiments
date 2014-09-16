#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;


int main() {

      /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

      int num_of_rocks = 0;

      std::cout << "Enter the number of rocks " << endl; 
      std::cin >> num_of_rocks;

      std::string *test = new std::string[num_of_rocks];
      assert(test != NULL);

      for ( int i = 0; i < num_of_rocks; i++){
            std::cout << "enter the string of rock -> " << i << endl;
            std::cin  >> test[i];
      }

      int i,j,k = 0;

       for ( i = 0 ; i < num_of_rocks; i++){
             for( j = 0; j < test[i].length(); j++ ){
                   for( k = j+1; k < test[i].length(); k++ ){
                         if(test[i][j] == test[i][k]){
                               test[i].erase(test[i].begin()+k);
                         }
                   }
             }
       }

      std::string alpha_set = "abcdefghijklmnopqrstuvwxyz";
      int *gem_count = new int[alpha_set.length()];      

      for (int i = 0 ; i < num_of_rocks; i++){
            for ( int j = 0; j < test[i].length(); j++ ){
                  for ( int k = 0 ; k < alpha_set.length(); k++ ){
                        if ( test[i][j] == alpha_set[k] ){
                              gem_count[k]++;
                        }
                  }
            }
      }

      int num_of_gems = 0;
      for ( int i = 0; i < alpha_set.length(); i++ ) {
            if( gem_count[i] == num_of_rocks){
                  std::cout << alpha_set[i] << endl;
                  num_of_gems++;
            }
      }

      std::cout << num_of_gems << endl;

      delete[] gem_count;
      delete[] test;

      return 0;
}
