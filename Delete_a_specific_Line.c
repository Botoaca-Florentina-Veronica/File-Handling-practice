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
                temp++;
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
        f2 = fopen("replica.c", "w");
        if(f2==NULL)
        {
            printf("Eroare de scriere in fisier!!!");
            exit(1);
        }
        deleteLine(f1, f2);
        fclose(f1);
        fclose(f2);
        //rename the file replica.c to original name
        rename("replica.c", fname);
        remove(fname);
        printf("\n The contents of file after being modified are as follows:\n");
        f1 = fopen(fname, "r");
        if(f1==NULL)
        {
            printf("Eroare de scriere in fisier!!!");
            exit(1);
        }
        while ((ch=fgetc(f1))!= EOF)
        {
            printf("%c", ch);
        }
        fclose(f1);
        return 0;
    }
