#include "stdio.h"
#include "string.h"
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int len=nums1Size+nums2Size;
    int num[len],tmp;
    double val;
    memcpy(num,nums1,nums1Size*sizeof(int));
    memcpy(num+nums1Size,nums2,nums2Size*sizeof(int));
       for(int i=0;i<len;i++)
        printf("%d\n",num[i]);
    for(int i=0;i<len;i++)
        for(int j=len-1;j>0;j--)
            if(num[j-1]>num[j])
            {    
                tmp=num[j-1];
                num[j-1]=num[j];
                num[j]=tmp;
            }
    for(int i=0;i<len;i++)
        printf("%d\n",num[i]);
    //if((nums1Size+nums2Size)%2==0)
    //    return val=(double)((num[(nums1Size+nums2Size-1)%2]+num[(nums1Size+nums2Size-1)%2+1]))/2;  
   // else
        return  val=(double)(num[(nums1Size+nums2Size-1)/2]);
    
}
void main()
{
    int n1[2]={1,3},n2[2]={2};
    printf("%f",findMedianSortedArrays(n1,2,n2,1));

}