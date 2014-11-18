#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int store_size = 10000;
//vector <long long int> temp_store(store_size,1);

long long int temp_store [store_size];

int generate_fact ( long long int i ){
    
    temp_store[0] = 1;
    temp_store[1] = 1;
    
    for ( long long int temp = 2; temp < i; temp++ ){
        temp_store[temp] = temp*temp_store[temp-1];
        cout << temp_store[temp] << endl;
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

    for(int i=0; i < set_size; i++){
        long long int temp = test_data[i];
        if ( temp == 1){
            cout << "0" <<endl;
        }else{
            cout << temp << " -- "<< endl;
            long long int temp_2 = temp * (temp-1)/2;
            cout << temp_2 << endl;
        }
    }

    return 0;
}
