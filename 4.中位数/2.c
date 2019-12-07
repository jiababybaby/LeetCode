#include "stdio.h"
void main()
{
    int num[4]={1,3,4,2};
    int tmp;
    for(int i=0;i<4;i++)
        for(int j=3;j>0;j--)
            if(num[j-1]>num[j])
            {    
                tmp=num[j-1];
                num[j-1]=num[j];
                num[j]=tmp;
            }
            //num[j-1]=num[j-1]>num[j]?num[j-1]:num[j];
    for(int i=0;i<4;i++)
     printf("%d",num[i]);
}