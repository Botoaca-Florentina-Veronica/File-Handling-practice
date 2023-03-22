/* C Program Delete a specific Line from a Text File */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int delete_line, temp = 1;
char ch, fname[40]="verasmechera.txt";
void deleteLine(FILE *f1, FILE *f2)
{
    while ((ch=fgetc(f1))!= EOF)
        {
            if (ch == '\n')
            {
                temp++;
            }
            //except the line to be deleted
            if (temp != delete_line)
            {
                //copy all lines in file replica.c
                fputc(ch, f2);
            }

        }
}
int main(void)
{
        FILE *f1, *f2;
        //open file in read mode
        f1 = fopen(fname, "r");
        if(f1==NULL)
        {
            printf("Eroare de citire din fisier!!!");
            exit(1);
        }
        while((ch=fgetc(f1))!=EOF)
        {
            printf("%c", ch);
        }
        //rewind
        rewind(f1);
        printf(" \n Enter line number of the line to be deleted: ");
        scanf("%d", &delete_line);
        //open new file in write mode
        f2 = fopen("replica.txt", "w");
        if(f2==NULL)
        {
            printf("Eroare de scriere in fisier!!!");
            exit(1);
        }
        deleteLine(f1, f2);
        fclose(f1);
        fclose(f2);
        remove(fname);
        //rename the file replica.c to original name
        rename("replica.txt", fname);
        printf("\n The contents of file after being modified are as follows:\n");
        f2 = fopen(fname , "r");
        if(f2==NULL)
        {
            printf("Eroare de scriere in fisier!!!");
            exit(1);
        }
        while ((ch=fgetc(f2))!= EOF)
        {
            printf("%c", ch);
        }
        printf("\n");
        fclose(f2);
        return 0;
    }




//almost same program but without rewind and delete line function:
/* C Program Delete a specific Line from a Text File */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int i, n=0, delete_line, enter=1;
    FILE *f1, *f2;
    char ch, fname[40]="verasmechera.txt";
    f1=fopen(fname, "r");
    f2=fopen("temp.txt", "w");
    if(f1==NULL || f2==NULL)
    {
        printf("Eroare citire din fisier!!");
        exit(1);
    }
    printf("Introduceti numarul liniei pe care doriti sa o stergeti: ");
    scanf("%d", &delete_line);
    while((ch=fgetc(f1))!=EOF)
    {
        printf("%c", ch);   //printez ce am in fisier
        n++;   //numarul de caractere din fisier
        if(ch=='\n')
        {
            enter++;
        }
        if(enter != delete_line)
        {
            fputc(ch, f2);
        }
    }
    printf("\n\n");
    fclose(f1);
    fclose(f2);

    remove(fname);
    rename("temp.txt", fname);

    f2=fopen(fname, "r");
    if(f2==NULL)
    {
        printf("Eroare de citire din fisier final!!");
        exit(1);
    }
    while((ch=fgetc(f2))!=EOF)
    {
        printf("%c", ch);
    }
    fclose(f2);
    return 0;
}
