//Afisati toate cuvintele dintr-un fisier cu prima litera fiind majuscula
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void functie_majuscula(char ch[100])
{
    if(islower(ch[0]))
    {
        ch[0]=toupper(ch[0]);
        printf("%c", ch[0]);
    }
    int i, n;
    n=strlen(ch);
    for(i=1; i<n; i++)
    {
        if(ch[i-1]==' ' && islower(ch[i]))
        {
            ch[i]=toupper(ch[i]);
            printf("%c", ch[i]);
            
        }
        else
        {
            printf("%c", ch[i]);
        }
    }
    
}
int main(void)
{
    FILE *f1;
    char ch[100];
    char fname[40]="verasmechera.txt";
    f1=fopen(fname, "r+");
    if(f1==NULL)
    {
        printf("Eroare!!!");
        exit(-1);
    }
    while(fgets(ch, 100, f1) != NULL)
    {
        functie_majuscula(ch);
    }
    printf("\n");
    return 0;
}
