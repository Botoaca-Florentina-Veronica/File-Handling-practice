//C Language Program to Count the Number of Lowercase Letters in a Text File
#include<stdio.h>
#include<String.h>
#include<stdlib.h>
int main(void)
{
    int k=0;
    char ch, fileName[20];
    printf("Introduceti numele fisierului: ");
    scanf("%s", &fileName);
    FILE *fp;
    fp=fopen(fileName, "r");
    if(fp==NULL)
    {
        printf("Eroare citire din fisier!!");
        exit(1);
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch>=97 && ch<=122)
        {
            k++;
        }
    }
    printf("NUmarul de litere mici este: %d", k);
    fclose(fp);
    return 0;
}
