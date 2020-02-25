#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution{
    public:
        class Bucket{
                public:
                    bool used=false;
                    int minval=numeric_limits<int>::max();
                    int maxval=numeric_limits<int>::min();
            };
        int maximumGap(vector<int>& nums){
            if(nums.size()<2) return 0;
            int mini=*min_element(nums.begin(),nums.end()),
            maxi=*max_element(nums.begin(),nums.end());
            //桶的大小和数量计算
            int bucketSize=max(1,(maxi-mini)/((int)nums.size()-1));
            int bucketNum=(maxi-mini)/bucketSize+1;
            vector<Bucket> buckets(bucketNum);
            for(auto&& num: nums){
                int bucketIdx=(num-mini)/bucketSize;
                buckets[bucketIdx].used=true;
                buckets[bucketIdx].minval=min(num,buckets[bucketIdx].minval);
                buckets[bucketIdx].maxval=max(num,buckets[bucketIdx].maxval);
            }
            int prevBucketMax=mini,maxGap=0;
            for(auto&& bucket:buckets){
                if(!bucket.used)
                    continue;
                maxGap=max(maxGap,bucket.minval-prevBucketMax);
                prevBucketMax=bucket.maxval;
            }
            return maxGap;
        } //桶排序 O(N)
        int maximumGap2(vector<int> nums){
            if(nums.size()<2) return 0;
            sort(nums.begin(),nums.end(),greater<int>());
            int maxGap=0;
            for(int i=0;i<nums.size()-1;i++){
                maxGap=max(maxGap,nums[i]-nums[i+1]);
            }
            return maxGap;
        }//快速排序 O(NlogN)
        int maximumGap3(vector<int> nums){
            if(nums.size()<2) return 0;
            int exp=1;
            int maxi=*max_element(nums.begin(),nums.end());
            while(maxi/exp>0){
                vector<vector<int>> tmp(10);
                for(int num:nums){
                    tmp[num/exp%10].push_back(num); 
                }
                int i=0;
                for(vector<int> t:tmp){
                   for(int num:t){
                       nums[i++]=num;
                   }
               }
                exp*=10;
            }
            // for(int num:nums){
            //    cout<<num<<' ';
            // } 
            int maxGap=0;
            for(int i=0;i<nums.size()-1;i++){
                maxGap=max(maxGap,nums[i+1]-nums[i]);
            }
            return maxGap;
        }//基数排序 O(N)
};
int main(){
    class Solution A;
    vector<int> nums={3,2,10,5,22,13,100,15,1,10 };
    cout<<A.maximumGap3(nums);
}