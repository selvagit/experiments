
#include <iostream>  

using namespace std;

class readint  
{ 
    private: 
        float a,b;  

    public:  

    void read() {
 
        cout<<"\n\nEnter the First Number : " << endl;  
        cin>>a; 
 
        cout<<"\n\nEnter the Second Number : " << endl;  
        cin>>b;  
    }  
    
    float get_a(){ return a;}
    float get_b(){ return b;}

    friend class sum;  
    //class sub;
};  

class sum  
{  
    public:  
        float c;  
        void add(readint rd)  
        {  
            c=rd.a+rd.b;  
            cout<<"\n\nSum="<<c;  
        }  
};  

class sub  
{  
    public:  
        float c;  
        void subtract(readint rd)  
        {  
            c=rd.get_a()-rd.get_b();  
            cout<<"\n\nSum="<<c;  
        }  
};  


int main()  
{  
    int cont;  
    readint rd;  
    sum s;  

    do  
    {  
        rd.read();  
        s.add(rd);  
        cout<<"\n\nDo you want to continue?(1-YES,0-NO)";  
        cin>>cont;  
    }while(cont==1);  
    
    sub temp;
    temp.subtract(rd);

    cin.get();  
}  

