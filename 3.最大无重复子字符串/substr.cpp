#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int start=0,end=0,length=0;
        for(int i=0;i<s.length();i++){
            end++;
            while(mp[s[i]]==1){
                mp[s[start]]=0;
                start++;
            }
            length=length>(end-start)?length:(end-start);
            mp[s[i]]=1;
        }
        return length;
    }
};
main(void)
{
    string p="pwwkew";
    class Solution A;
    cout<<A.lengthOfLongestSubstring(p);
}