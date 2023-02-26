//C program that prints in descending order the unique occurences of all numbers in a file
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int i,j,n=0, temp, v[500], c, *x, k;
void bubbleSort(int *v, int n)
{
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(v[j]<v[j+1])
            {
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}
int main (void)
{
    int *temp;
    char fname[30]="verasmechera.txt";
    FILE *f1;
    f1=fopen(fname, "r");
    if(f1==NULL)
    {
        printf("Reading error!!!");
        exit(1);
    }
    while(fscanf(f1, "%d", &c)!=EOF)
    {
        temp=realloc(x, (n+1)*sizeof(int));
        if(temp==NULL)
        {
            printf("Eroare!!");
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
    k=0;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(x[i]==x[j])
            {
                for(k=j; k<n-1; k++)
                {
                    x[k]=x[k+1];
                }
                n--;
                j--;
            }

        }
    }
    fclose(f1);
    f1=fopen(fname, "w");
    if(f1==NULL)
    {
        printf("Writing error!!");
        exit(1);
    }
    for(i=0; i<n; i++)
    {
        fprintf(f1, "Sorted number: %d\n", x[i]);
        printf("Sorted number: %d\n", x[i]);
    }
    fclose(f1);
    free(x);
    return 0;
}
