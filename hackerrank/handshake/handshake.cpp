#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int store_size = 10;
vector <long long int> temp_store(store_size,0);

int generate_fact ( long long int i ){
    
    temp_store[0] = 1;
    temp_store[1] = 1;
    
    for ( long long int temp = 2; temp < i; temp++ ){
        temp_store[i] = temp*temp_store[temp-1];
    }
    return 0;
}


long long int my_factorial ( long long int i){

    long long int temp;
    
    if ((i == 0)||(i == 1))
        return 1;
    else 
        return i*my_factorial (i-1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int set_size = 0;
       
    cin >> set_size;
    
    generate_fact(store_size);
    
    vector <long long int> test_data;
    
    for(int i=0; i < set_size; i++){
        long long int temp;
        cin >> temp;
        test_data.push_back(temp);
    }
    
/*    
    for(int i=0; i < set_size; i++){
        long long int temp = test_data[i];
        if ( temp == 1){
            cout << "0" <<endl;
        }else{
            long long int temp_2 = my_factorial(temp-2)*(long long int)2;
            temp_2 = my_factorial(temp)/temp_2;
            cout << temp_2 << endl;
        }
    }
*/    
     for(int i=0; i < set_size; i++){
        long long int temp = test_data[i];
        if ( temp == 1){
            cout << "0" <<endl;
        }else{
            long long int temp_2 = temp_store[temp-2]*2;
            temp_2 = temp_store[temp]/temp_2;
            cout << temp_2 << endl;
        }
    }
    
    return 0;
}
