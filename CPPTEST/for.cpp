#include <iostream>
#include <vector>
using namespace std;
main()
{
    string str="abcdefghijklmnopqrstuvwxyz";
    str+='9';
    for(char c : str)
        cout<<c;
    vector<string> strs;
    strs.push_back("abcd");
    strs.push_back("1234");
    strs.push_back("efgh");
    for(string c:strs)
        cout<<c;
        cout<<strs[0].length();
}