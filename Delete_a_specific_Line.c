/* C Program Delete a specific Line from a Text File */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void deleteLine(FILE *f1, FILE *f2, int n)
{
    char ch;
    int count=1;
    while(fscanf(f1, "%c", &ch)!=EOF)
    {
        if(ch == '\n')
        {
            count++;
        }
        if(count!=n)
        {
            //atunci am ajuns la linia pe care dorim sa o stergem
            fputc(ch, f2);
        }

    }
}


int main(void)
{
    int  n;
    char fname[30]="verasmechera.txt";
    FILE *f1, *f2;
    f1=fopen(fname, "r");
    f2=fopen("temp.txt", "w");
    if(f1==NULL && f2==NULL)
    {
        printf("Eroare la citirea din fisier!");
        free(f1);
        free(f2);
        exit(1);
    }
    printf("Introduceti numarul liniei pe care doriti sa o stergeti din fisier!\n");
    scanf("%d", &n);

    deleteLine(f1, f2, n);

    fclose(f1);
    fclose(f2);

    remove(fname);
    rename("temp.txt", fname);

    f2=fopen(fname, "r");
    if(f2==NULL)
    {
        printf("Eroare la scrierea in fisier!");
        free(f2);
        exit(1);
    }

    char ch;
    //acum printam ce avem in f2 direct in termial
    while((ch=fgetc(f2))!=EOF)
    {
        printf("%c", ch);
    }

    fclose(f2);
    return 0;
}
