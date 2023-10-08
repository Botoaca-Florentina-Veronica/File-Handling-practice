//C program that replaces capital letters with small ones and viceversa.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void replaceLetters(FILE *f1, FILE *f2)
{
    char ch;
    while(fscanf(f1, "%c", &ch)!=EOF)
    {
        if(ch>='A' && ch<='Z')
        {
            ch=tolower(ch);
            fputc(ch, f2);
        }
        else if(ch>='a' && ch<='z')
        {
            ch=toupper(ch);
            fputc(ch, f2);
        }
        else
        {
            //adica caracterul actual nu e litera, deci orice ar fi, il vom pune in fisierul final
            fputc(ch, f2);
        }
    }
}


int main(void)
{
    char ch, fname[30]="verasmechera.txt";
    FILE *f1, *f2;
    f1=fopen(fname, "r");
    f2=fopen("temp.txt", "w");
    if(f1==NULL && f2==NULL)
    {
        printf("Eroare la citirea si scriera in fisierele f1 si f2!");
        free(f1);
        free(f2);
        exit(1);
    }

    replaceLetters(f1, f2);

    fclose(f1);
    fclose(f2);

    remove(fname);
    rename("temp.txt", fname);

    f2=fopen(fname, "r");
    if(f2==NULL)
    {
        printf("Eroare la citirea fisierului final!!");
        free(f2);
        exit(1);
    }

    //acum printam tot ce se afla in fisierul final
    while((ch=fgetc(f2))!=EOF)
    {
        printf("%c", ch);  //printam ce se afla in fisierul f2 fiindca deja avem ce trebuie in f2 dupa efectuarea functiei replaceLetters
    }

    fclose(f2);

    //nu uita de fclose!
    return 0;
}
