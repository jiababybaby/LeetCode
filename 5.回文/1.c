#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b
int expandAroundCenter(char *s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < strlen(s) && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}
char * longestPalindrome(char * s){
    if (s == NULL || strlen(s) < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < strlen(s); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    char *p;
    p=(char *)malloc((end-start)*sizeof(char));
    memset(p,'0',end-start);
    strncpy(p,s+start,end-start+1);
    p[end-start+1]='\0';
    return p;
}
void main(){
    char *s="babad";
    printf("%s\n",longestPalindrome(s));
}


