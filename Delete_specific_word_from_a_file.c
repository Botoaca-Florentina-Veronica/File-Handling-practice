//A program which delete the given word in a txt file and write the result to another txt file.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char word_to_delete[100];
    char *word, *token, *rest_of_line, line[1000];
    int word_deleted = 0;
    FILE *f1, *f2;
    char fname[40]="verasmechera.txt";

    f1=fopen(fname, "r");
    f2=fopen("temp.txt", "w");

    if(f1==NULL || f2==NULL)
    {
        printf("Eroare fisiere!!!");
        exit(1);
    }
    printf("Introduceti cuvantul pe care doriti sa il stergeti din fisier: ");
    scanf("%s", word_to_delete);

     while (fgets(line, 1000, f1))
    {
        // Tokenize line by whitespace
        
        
        //strtok_r() is a reentrant version of the strtok() function in C. 
        //It is used to tokenize a string just like strtok(), 
        //but it allows multiple strings to be tokenized simultaneously 
        //without interfering with each other(used for text with multiple lines).
        rest_of_line = line;
        while ((token = strtok_r(rest_of_line, " \t\n", &rest_of_line)))
        {
            // Check if token is the word to delete
            if (strcmp(token, word_to_delete) == 0)
            {
                word_deleted = 1;
            }
        else
            {
                // Write token to output file
                fprintf(f2, "%s ", token);
            }
        }
        // Write end of line to output file
        fprintf(f2, "\n");
    }

    // Close input and output files
    fclose(f1);
    fclose(f2);
    return 0;
}
