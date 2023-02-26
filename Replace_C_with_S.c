//Program in C to Replace Capital C with Capital S in a File
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp1,*fp2;
    char ch, fname[40]="verasmechera.txt";
    fp1=fopen(fname,"r");
    fp2=fopen("temp.txt","w");
    if(fp1==NULL)
    {
        printf("Error while opening a file for reading");
        exit(1);
    }
    if(fp2==NULL)
    {
        printf("Error while opening a file for writing");
        exit(1);
    }
    printf("Before Replacing capital C\n");
    while((ch=fgetc(fp1))!=EOF)
    {
        printf("%c",ch);  //printing on compiler what is in the file
        if(ch=='C')
        {
            fputc('S',fp2);
        }
        else
        {
            fputc(ch,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove(fname);
    rename("temp.txt",fname);  
    fp2=fopen(fname,"r");
    if(fp2==NULL)
    {
        printf("Error while opening for reading");
        exit(1);
    }
    printf("\n");
    printf("\nAfter Replacing capital C with S\n");
    while((ch=fgetc(fp2))!=EOF)
    {
       printf("%c",ch);
    }
    fclose(fp2);
    return 0;
}
