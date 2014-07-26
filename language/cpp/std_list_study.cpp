 // list constructors

#include <list>
#include <iostream>

using namespace std;
 

int main()
{

    list <int>::iterator li0Iter, li1Iter, li2Iter, li3Iter, li4Iter, li5Iter, li6Iter;

    // ----------------------------------------------------
    // create an empty list li0
    list <int> li0;

    cout<<"Operation: list <int> li0\n";

    cout<<"li0 data: ";

    for(li0Iter = li0.begin(); li0Iter != li0.end(); li0Iter++)
        cout<<" "<<*li0Iter;

    cout<<endl;

    // ----------------------------------------------------
    // create a list li1 with 10 elements of default value 0
    list <int> li1(10);

    cout<<"\nOperation: list <int> li1(10)\n";

    cout<<"li1 data: ";

    for(li1Iter = li1.begin(); li1Iter != li1.end(); li1Iter++)
        cout<<" "<<*li1Iter;

    cout<<endl;

    // ----------------------------------------------------
    // create a list li2 with 8 elements of value 7
    list <int> li2(8, 7);

    cout<<"\nOperation: list <int> li2(8, 7)\n";

    cout<<"li2 data: ";

    for(li2Iter = li2.begin(); li2Iter != li2.end(); li2Iter++)
        cout<<" "<<*li2Iter;

    cout<<endl;

    // ----------------------------------------------------
    
    // create a list li3 with 9 elements of value 8 and with the allocator of list li2
    list <int> li3(9, 8, li2.get_allocator());

    cout<<"\nOperation: list <int> li3(9, 8, li2.get_allocator())\n";

    cout<<"li3 data: ";

    for(li3Iter = li3.begin(); li3Iter != li3.end(); li3Iter++)
        cout<<" "<<*li3Iter;

    cout<<endl;

    // ----------------------------------------------------
    // li4, a copy of list li2
    list <int> li4(li2);

    cout<<"\nOperation: list <int> li4(li2);\n";

    cout<<"li4 data: ";

    for(li4Iter = li4.begin(); li4Iter != li4.end(); li4Iter++)
        cout<<" "<<*li4Iter;

    cout<<endl;

    // create a list li5 by copying the range of li4[_First, _Last)
    li4Iter = li4.begin();
    li4Iter++;
    li4Iter++;
    li4Iter++;
    li4Iter++;
    list <int> li5(li4.begin(), li4Iter);

    cout<<"\nOperation1: li4Iter = li4.begin(), li4Iter++...\n";

    cout<<"Operation2: list <int> li5(li4.begin(), li4Iter)\n";

    cout<<"li5 data: ";

    for(li5Iter = li5.begin(); li5Iter != li5.end(); li5Iter++)
        cout<<" "<<*li5Iter;

    cout<<endl;

    // create a list li6 by copying the range of li4[_First, _Last) and with the allocator of list li2
    li4Iter = li4.begin();
    li4Iter++;
    li4Iter++;
    li4Iter++;
    list <int> li6(li4.begin(), li4Iter, li2.get_allocator());

    cout<<"\nOperation1: li4Iter = li4.begin(), li4Iter++...\n";

    cout<<"Operation2: list <int> li6(li4.begin(), li4Iter,\n"

        "    li2.get_allocator())\n";

    cout<<"li6 data: ";

    for(li6Iter = li6.begin(); li6Iter != li6.end(); li6Iter++)
        cout<<" "<<*li6Iter;

    cout<<endl;

    return 0;

}
