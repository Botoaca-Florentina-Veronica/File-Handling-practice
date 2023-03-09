//C program that capitalize every word in a file and prints it on the screen. 
//Use a function for capitalizing.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(void)
{
    int i, n=0;
    char ch, fname[40]="verasmechera.txt";
    FILE *f1, *f2;
    f1=fopen(fname, "r");
    f2=fopen("temp.txt", "w");
    if(f1==NULL && f2==NULL)
    {
        printf("Eroare fisiere!!");
        exit(1);
    }
    while((ch=fgetc(f1))!=EOF)
    {
        printf("%c", ch);  //printam elementele pe ecran
        n++;  //numaram sa vedem cate caractere avem in fisier

        if(ch>=97 && ch<=122)
        {
            ch=toupper(ch);
        }

        for(i=0; i<n; i++)
        {
            if(ch==' ')
            {
                ch=toupper(ch);
            }
        }
    }
    while((ch=fgetc(f1))!=EOF)
    {
        fprintf(f2, "%c", ch);
    }

    fclose(f1);
    fclose(f2);


    remove(fname);
    rename("temp.txt", fname);

    f2=fopen(fname, "r");
    if(f2==NULL)
    {
        printf("Eroare fisier");
        exit(1);
    }

    while((ch=fgetc(f2))!=EOF)
    {
        printf("%c", ch);
    }

    fclose(f2);
    return 0;
}
