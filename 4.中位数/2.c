#include "stdio.h"
#include "string.h"
#define max(a,b) ( ((a)>(b)) ? (a):(b) )
#define min(a,b) ( ((a)>(b)) ? (b):(a) )

double findKthSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size,int k){
    int len=nums1Size+nums2Size;
    int le=max(0,k-nums2Size),ri=min(k,nums1Size);
    while(le<ri)
    {
        int m=le+(ri-le)/2;
        if(nums2[k-m-1]>nums1[m]) le=m+1;
        else ri=m;
    }
   
    int nums1LeftMax=le==0?0:nums1[le-1];
    int nums2LeftMax=le==k?0:nums2[k-le-1];
    if(le==0) return nums2[k-le-1];
    if(le==k) return nums1[le-1];  
    return max(nums1LeftMax,nums2LeftMax);
    
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int len=nums1Size+nums2Size;
    if(len&1)
        return (double)findKthSortedArrays(nums1,nums1Size,nums2,nums2Size,(len>>1)+1);
    else 
        return (double)((findKthSortedArrays(nums1,nums1Size,nums2,nums2Size,len>>1)+findKthSortedArrays(nums1,nums1Size,nums2,nums2Size,(len>>1)+1))/2);
   
    
}
void main()
{
    int n1[1]={3},n2[2]={-2,-1};
    // for(int i=1;i<6;i++)
    // printf("%f\n",findKSortedArrays(n1,2,n2,3,i));
    printf("%f",findMedianSortedArrays(n1,1,n2,2));
}