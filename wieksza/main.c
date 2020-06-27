#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * funkcja(char *z1, char *z2);

int main()
{
    char * znak1="AAaaaaeeeA";
    char * znak2="EeEeEEeEEyuyoi";
    printf("\n%s",funkcja(znak1,znak2));

    return 0;
}
char * funkcja(char *z1, char *z2)
{
int i=0;
int ilejestz1=0;
int ilejestz2=0;

while(z1[i]!=0)
{
    if(z1[i]>='a' && z1[i]<='z')
       {
        ilejestz1++;
       }
    i++;
}
i=0;
while(z2[i]!='\0')
{
    if(z2[i]>='a' && z2[i]<='z')
        ilejestz2++;
    i++;
}
printf("%d:%d", ilejestz1,ilejestz2);

if(ilejestz1>ilejestz2)
    return z2;
else
    return z1;
}
