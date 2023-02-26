//program in c that prints the characters in a file in reverse order
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    FILE *f1, *f2;
    char ch, fname[40]="verasmechera.txt";
    f1=fopen(fname, "r");
    f2=fopen("temp.txt", "w");
    if(f1==NULL || f2==NULL)
    {
        printf("Error opening file(s)!!!");
        exit(1);
    }
    //now we go to the end of the file using the fseek function
    fseek(f1, 0, SEEK_END);
    //after being at the end of the file, we can use the ftell function to tell us the index number of where it is currently
    //and because it is at the end of the file, that means it is going to return the lentgh of it
    int length = ftell(f1);
    fseek(f1, -1, SEEK_CUR);
    while(length>0)
    {
        ch=fgetc(f1);
        fputc(ch, f2);

        printf("%c", ch);

        fseek(f1, -2, SEEK_CUR);

        length--;
    }
    fclose(f1);
    fclose(f2);
    remove(fname);
    rename("temp.txt", fname);
    return 0;
}
