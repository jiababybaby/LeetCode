#include "stdio.h"
#include "stdbool.h"
int sumv(int n){
    int sum=0;
    int num[50]={0},i=0;
    while(n>=1){
        num[i]=n%10;
        n=n/10;
        i++;
    }
    // for(int j=0;j<i;j++)
        // printf("%d",num[j]);
    for(int j=0;j<i;j++){
        sum=sum+num[j]*num[j];
    }
    printf("%d\n",sum);
    return sum;
}
bool isHappy(int n){
    int val;
    int mash[500]={0};
    val=sumv(n);
    mash[val]=1;
    // printf("\n\n\n%d\n\n\n",val);
    while(val!=1){
        val=sumv(val);
        // printf("\n\n\n%d\n\n\n",val);
        if(mash[val]==1){
            return false;
        }
        mash[val]=1;
        
    }
    return true;    
}
void main()
{
    int n=19;
    if(isHappy(n))
        printf("%d is true happy\n",n);
    else
    {
        printf("%d is false happy\n",n);
    }
    
}