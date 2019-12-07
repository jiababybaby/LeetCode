class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len;
        vector<int> a;
        len=nums.size();
        for(int i=0;i<len-1;i++)
            for(int j=i+1;j<len;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    a.push_back(i);
                    a.push_back(j);
                    return a;
                }
            }
        return a;
    } 
};