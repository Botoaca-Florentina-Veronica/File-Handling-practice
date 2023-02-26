//Read the file and count the number of lines
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int i,k=1;  //k-counter
    char c;
    FILE *in=fopen("file3.txt", "r");
    if(in==NULL)
    {
        printf("Error!!");
        exit(1);
    }
    // Extract characters from file and store in character c
    for(c=getc(in); c!=EOF; c=getc(in))
    {
        if(c=='\n')   //Increment count if this character is newline
        {
            k=k+1;
        }
    }
    fclose(in);
    printf("Number of line in the file is: %d", k);
    return 0;
  
