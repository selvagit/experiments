#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    string num ;
    getline(cin, num);
    stringstream(num) >> n;

    char temp[255];
    string name;
    int number;
    
    std::map<string,int> database;
    
    for(int i=0; i<n; i++) {
        cin.getline( temp , 255);
	string name(temp) ;
	cout << "1:" << name << endl;
	name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
        cin >> number;
        database[name] = number;
	cout << "2:" << name << endl;
    }
    
    for (int i=0; i<n; i++) {
        cin.getline(temp,255);
	string name(temp)
	name.erase(std::remove(name.begin(), name.end(), ' '), name.end());
	cout << "Test :" << name  << endl; 
        if ( database.find(name) == database.end() ) {
            cout << "Not found" << endl;
        }else
        {
            cout << name << "=" << database[name] << endl;
        }
    }   
    
    return 0;
}

