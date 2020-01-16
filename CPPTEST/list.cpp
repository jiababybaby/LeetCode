#include <iostream>
#include <list>

using namespace std;

class Ss{

public:
    int i;
    Ss(int a=0):i(a)
    {
        
    }
    ~Ss(){
        cout<<"Ïú³ý"<<i<<endl;
    }

};
main()
{
    list<int> A;
    A.push_back(10);
    A.push_back(2);
    A.push_back(3);
    list<int>::iterator i;
    for(i=A.begin();i!=A.end();++i)
    {
        cout<<*i<<" ";
    }
    Ss s(10);
    cout<<s.i;
}