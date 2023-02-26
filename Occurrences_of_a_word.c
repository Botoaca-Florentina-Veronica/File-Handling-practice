// C program to count occurrences of a word in file.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countOccurrences(FILE *f1, const char *word);
int main(void)
{
    FILE *f1;
    char fname[40]="verasmechera.txt", word[50];
    int wCount;
    printf("Type the word that you want to find in the file: ");
    scanf("%s", word);
    f1 = fopen(fname, "r");
    if (f1 == NULL)
    {
        printf("Reading error!!!");
        exit(1);
    }
    wCount = countOccurrences(f1, word);
    printf("'%s' is found %d times in this file", word, wCount);
    fclose(f1);
    return 0;
}

int countOccurrences(FILE *f1, const char *word)
{
    char str[1000], *pos;
    int count=0;
    //fgets reads one line and strstr only tells you whether (and where) a string appears in that line
    while ((fgets(str, 1000, f1)) != NULL)
    {
        char *pos=str;
        while ((pos = strstr(pos, word)) != NULL)
        {
            count++;
            pos++;
        }
    }
    return count;   //trb neaparat fiindca avem int
}
//cand trebuie sa atribui functia unei variabile nu volosim void ci int la declararea ei
