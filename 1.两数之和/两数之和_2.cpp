#include <map>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len;
        vector<int> a;
        len=nums.size();
        map<int,int> ret;
        for(int i=0;i<len;i++){
            int r=target-nums[i];
            if(ret.find(r)!=ret.end()){
                a.push_back(i);
                a.push_back(ret.find(r)->second);
                return a;
            }
            ret[nums[i]]=i;
        }
        return a;
    } 
};
main(){
    vector<int> nums={2,7,11,15};
    vector<int> num;
    int target=9;
    class Solution A;
    num=A.twoSum(nums,target);
    cout<<num[0]<<num[1];
}