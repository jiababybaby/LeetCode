#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int i=0,firstnum=0,res=0,sign=0;
        while(str[i] == ' ') i++;
        for(;i<str.size();i++){
            if(!isdigit(str[i])&&str[i]!='-'&&str[i]!='+'&&!firstnum) return 0;
            if(!isdigit(str[i])&&firstnum) break; 
            if(str[i]=='-') sign=1;
            if(str[i]=='-'||str[i]=='+'){
                firstnum=1;
                continue;
            } 
            if(res>INT_MAX/10||(res==INT_MAX/10&&str[i]>'7')) return sign==1? INT_MIN:INT_MAX;
            res =res*10+(str[i]-'0') ;
            firstnum=1;
        }
        return sign==1? ~res + 1:res;
    }
};
main()
{
    class Solution A;
    cout<<A.myAtoi("     -123q");

}