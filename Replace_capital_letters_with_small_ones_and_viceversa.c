//C program that replaces capital letters with small ones and viceversa.
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include<ctype.h>
int main(void)
{
    FILE *fp1,*fp2;
    char ch, fname[40]="verasmechera.txt";
    fp1=fopen(fname,"r");
    fp2=fopen("temp.txt","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("Error with files!!!");
        exit(1);
    }
    printf("\n");
    while((ch=fgetc(fp1))!=EOF)
    {
        printf("%c",ch);  //printing on compiler what is in the file
        if(ch>=97 && ch<=122)
        {
            ch=toupper(ch);
            fputc(ch, fp2);
        }
        else if(ch>=65 && ch<=90)
        {
            ch=tolower(ch);
            fputc(ch, fp2);
        }
        else
        {
            fputc(ch, fp2);
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
    while((ch=fgetc(fp2))!=EOF)
    {
       printf("%c",ch);
    }
    fclose(fp2);
    return 0;
}
