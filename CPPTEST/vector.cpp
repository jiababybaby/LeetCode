#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<int> v;
    for(int n=0;n<5;++n)
        v.push_back(n);
    vector<int>::iterator i;
    for(i=v.begin();i!=v.end();++i){
        cout<<*i<<" ";
        *i *=2;
    }
    cout<<endl;
    for(vector<int>::reverse_iterator j=v.rbegin();j!=v.rend();++j)
        cout<<*j<<" ";
    vector<int>::iterator k;
    k=v.end();
    cout<<endl<<*(k-1)<<endl;
    int a[4]={5,1,8,2};
    sort(a,a+4);
    for(int i=0;i<4;i++)
    cout<<*(a+i)<<endl;
    return 0;
}