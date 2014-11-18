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
    
    for ( int i=0; i < set_number; i++ ){
        int temp;
        cin >> temp;
        set_list.push_back(temp);
    }
    
    for ( int i =0; i < set_number; i++ ){
        cout << (long long int)(1<<set_list[i])-1 << endl;
    }
    
    return 0;
}

