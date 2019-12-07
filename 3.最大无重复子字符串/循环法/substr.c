#include "string.h"
#include "stdio.h"
int longsubstr(char *s)
{   int len,returnval=1;
    len=strlen(s);
    int a[len];
    for(int i=0;i<len;i++)
    {   a[i]=1;
        for(int j=i+1;j<len;j++)
            if(s[i]!=s[j])
                a[i]++;
            else
                break;
    }
 
    for(int i=0;i<len;i++)
    {
        for(int j=1;j<a[i];j++)
        {
            if(a[i+j]<(a[i]-j))
            {
                printf("a[%d]%d a[%d]%d\n",i,a[i],i+j,a[j]);
                a[i]=j+a[i+j];
                printf("a[%d]%d a[%d]%d\n",i,a[i],i+j,a[j]);
                
            }
        }
    }
    for(int i=0;i<len-1;i++)
    {
        if(a[i]>a[i+1])
            a[i+1]=a[i];
    }
    // for(int i=0;i<len-1;i++)
    // {
    //     printf("%d\n",a[i]);
    // }
    return a[len-1];


}
int lengthOfLongestSubstring(char * s){
    return longsubstr(s);

}
void main(void)
{
    char *p="uqinntq";
    printf("%d\n",lengthOfLongestSubstring(p));
}