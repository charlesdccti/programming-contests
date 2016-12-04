#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str1[82];
    scanf("%s%*c", str1);
    int len = strlen(str1);

    char str2[len], str3[len], str4[len];
    scanf("%s%*c", str2);
    scanf("%s%*c", str3);
    scanf("%s%*c", str4);

    int F = (str1[0]-'0')*1000 + (str2[0]-'0')*100 + (str3[0]-'0')*10 + (str4[0]-'0')*1;
    int L = (str1[len-1]-'0')*1000 + (str2[len-1]-'0')*100 + (str3[len-1]-'0')*10 + (str4[len-1]-'0')*1;
    int i;
    int M;
    
    for(i=1; i<len-1; i++){
        M = (str1[i]-'0')*1000 + (str2[i]-'0')*100 + (str3[i]-'0')*10 + (str4[i]-'0')*1;
        printf("%c", (F*M + L)%257);
    }
    printf("\n");

    return 0;
}