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
    int fast,slow;
    slow=sumv(n);
    fast=sumv(sumv(n));
    while(slow!=1&&fast!=1){
        slow=sumv(slow);
        fast=sumv(sumv(fast));
        if((slow==fast)&&fast!=1){
            return false;
        }
    }
    return true;    
}
void main()
{
    int n=20;
    if(isHappy(n))
        printf("%d is true happy\n",n);
    else
    {
        printf("%d is false happy\n",n);
    }
    
}