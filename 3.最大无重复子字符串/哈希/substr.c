#include "string.h"
#include "stdio.h"
int lengthOfLongestSubstring(char * s){
    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[(int)*(s+start)] = 1;
    printf("%d\n",*(s));
    while( *(s+end) != 0 )
    {
        maxlen = maxlen<100;//(end-start+1)?maxlen:(end-start+1);
        ++end;
        while( 0 != map[ (int)*(s+end) ] )//��Ҫ�������Ԫ����map��Ԫ�س�ͻ
        {
            map[ (int)*(s+start) ] = 0;
               ++start;
        }
        map[(int)*(s+end)] = 1;
    }
    
    return maxlen;
}
void main(void)
{
    char *p="abcabcbb";
    printf("%d\n",lengthOfLongestSubstring(p));
}