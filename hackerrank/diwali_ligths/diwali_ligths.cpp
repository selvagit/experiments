#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int set_number = 0;
    
    cin >> set_number;
    
    vector <int> set_list ;
    
    for (int i=0; i < set_number; i++){
        int temp;
        cin >> temp;
        set_list.push_back(temp);
    }
    
    for (int j =0 ; j < set_number; j++) {
        int p = set_list[j];
    
        long long int temp = 1;
        for ( int i =0; i < p; i++ ){
            temp = temp << 1;
            if (temp >= 100000)
                temp = temp - 100000;
        }

        cout << temp-1 << endl;
    }
    
    return 0;
}

