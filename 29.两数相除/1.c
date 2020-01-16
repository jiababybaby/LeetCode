#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000
int divide(int dividend, int divisor){
        if (dividend == -pow(2, 31) && divisor == -1)
        		return 2147483647;
        if (dividend == -pow(2, 31) && divisor == 1)
            return -pow(2,31);
        if(dividend != -pow(2, 31) && divisor == -pow(2, 31))
            return 0;
        if (dividend == -pow(2, 31) && divisor == -pow(2, 31))
            return 1;

        int i,flag,flagneg=1,breakflag=0;
        if ((dividend < 0 && divisor > 0)|| (dividend > 0 && divisor < 0))
                flagneg=-1;
        if(dividend>0) dividend=0-dividend;
        if(divisor>0) divisor=0-divisor;
        printf("%d",flagneg);
        printf("dividend: %d\n",dividend);
        flag=divisor;
        printf("divisor: %d\n",divisor);
        if(dividend>divisor)
            return 0;
        if(dividend==divisor)
            return flagneg==-1?-1:1;
        i=1;
        while((dividend-flag)<=0)
        {   if((i>(INT_MAX>>1))||abs(flag)>(INT_MIN>>1))
            {   breakflag=1;
                break;
            }
            i=i<<1;
            flag+=flag;
            printf("flag:%d\n",flag);
            printf("i:%d\n",i);
        }
        printf("%d\n",i);
        printf("flag:%d\n",flag);
        if(breakflag==1)
        {
            if(abs(dividend-(flag))==0)
                return flagneg==-1?~(i)+1:i;
            else if (abs(dividend-(flag))<abs(divisor))
            {
                return flagneg==-1?~(i)+1:i;
            }
            else if (abs(flag-dividend)<abs(divisor))
            {
                return flagneg==-1?~(i-1)+1:i-1;
            }else
            {
                return  flagneg==-1?~((i)+divide(dividend-(flag),divisor))+1:(i)+divide(dividend-(flag),divisor);
            }
        }else{
            if(abs(dividend-(flag>>1))==0)
                return flagneg==-1?~(i>>1)+1:i>>1;
            else if (abs(dividend-(flag>>1))<abs(divisor))
            {
                return flagneg==-1?~(i>>1)+1:i>>1;
            }
            else if (abs(flag-dividend)<abs(divisor))
            {
                return flagneg==-1?~(i-1)+1:i-1;
            }else
            {
                return  flagneg==-1?~((i>>1)+divide(dividend-(flag>>1),divisor))+1:(i>>1)+divide(dividend-(flag>>1),divisor);
            }
        }
}
void main()
{
    printf("%d\n",divide(1100540749,-1090366779));
}