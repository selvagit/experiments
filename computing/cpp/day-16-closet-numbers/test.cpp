#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int n;
    cin >> n;
    
    vector<int> data;
    
    for ( int i=0 ; i<n; i++ ) {
        int e;
        cin >> e;
        data.push_back(e);
    }
    
    int list_size = data.size();
    for ( int i=0; i<list_size-1; i++ ) {
        int temp = data[i];
        for ( int j=i+1; j<list_size; j++ ) {
 
            if (temp < data[j]) {
                data[j-1] = data[j];
            } else {
                data[j-1] = temp;
                break;
            }
        }
    }
    
    
    vector<vector<int> > diff_data;
    int diff = 0xffffffff;
    int prev_diff = 0xffffffff;
    list_size = data.size();
    
    for (int i=0; i<list_size-1; i++ ) {
        int temp = data[i];
        for (int j=1; j<list_size; j++ ) {
 
            if ( abs (temp - data[j]) <= diff ){
                prev_diff = diff;
                diff = abs(temp-data[j]);
                vector <int> diff_set;
                diff_set.push_back(temp);
                diff_set.push_back(data[j]);
                diff_set.push_back(diff);
                if(diff_data.size() != 0 ){
                    if ( diff != prev_diff ){
                        int diff_data_sz = diff_data.size(); 
                        while(diff_data_sz--)
                            diff_data.pop_back();
                    } else {
                        diff_data.push_back(diff_set);
                    }
                    
                }    
            }
        }
    }

    list_size = diff_data.size();
    for ( int i=0; i<list_size; i++){
        vector <int> diff_set = diff_data.back();
        diff_data.pop_back();
        cout << diff_set[0] << diff_set[1] << diff_set[2];
    }
    
    return 0;
}
