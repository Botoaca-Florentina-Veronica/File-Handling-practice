//C program that sorts in ascending order the numbers in a file and also prints it on the compiler
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int i,n=0,j,temp;  //n is the number of numbers in the file
int *x, c;
void bubbleSort(int *v, int n)
{
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(v[j]>v[j+1])
            {
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}
int main(void)
{
    int *temp;
    char fname[20]="verasmechera.txt";
    FILE *f1;
    f1=fopen(fname, "r");
    if(f1==NULL)
    {
        printf("Reading error!!");
        exit(1);
    }
    while(fscanf(f1, "%d", &c)!=EOF)
    {
        temp=realloc(x, (n+1)*sizeof(int));
        if(temp==NULL)
        {
            printf("Eroare!!!");
            free(x);
            exit(1);
        }
        x=temp;
        x[n]=c;
        n++;   
    }
    for(i=0; i<n; i++)
    {
        fscanf(f1, "%d", &x[i]);
        printf("Number: %d\n", x[i]);
    }
    printf("\n");
    bubbleSort(x, n);
    fclose(f1);
    f1=fopen(fname, "w");
    if(f1==NULL)
    {
        printf("Writing error!!");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        fprintf(f1, "Sorted number: %d\n", x[i]);
        printf("Sorted number: %d\n", x[i]);
    }
    fclose(f1);
    free(x);
    return 0;
}