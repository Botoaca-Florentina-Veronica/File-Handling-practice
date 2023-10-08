//C program that sorts in ascending order the numbers in a file and also prints it on the compiler
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void bubbleSort(int *v, int n)
{
    int i,j,temp;  
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
    int *v, num, count=0, i;
    char fname[20]="verasmechera.txt";
    FILE *f1, *f2;
    f1=fopen(fname, "r");
    f2=fopen("temp.txt", "w");
    if(f1==NULL || f2==NULL)
    {
        printf("Reading or writing in file error!!");
        exit(1);
    }
    while(fscanf(f1, "%d", &num)!=EOF)
    {
        //practic num reprezinta fiecare numar din fisier
        v=realloc(v, (count+1)*sizeof(int));
        if(v==NULL)
        {
            printf("Eroare!!!");
            free(v);
            exit(1);
        }
        v[count]=num; //aici imi pun in vectorul v fiecare numar preluat din fisier
        count++;  //aici vreau practic sa va cate numere am in fisier
        //asa ca la fiecare pas voi adauga +1
    }
    printf("Initial content of the file:\n");
    for(i=0; i<count; i++)
    {
        fscanf(f1, "%d", &v[i]);
        printf(" %d\n", v[i]);
    }
    printf("\n");
    bubbleSort(v, count);

    printf("Sorted numbers:\n");
    for(i=0; i<count; i++)
    {
        fprintf(f2, "%d\n", v[i]);
        printf("%d\n", v[i]);
    }

    fclose(f1);
    fclose(f2);

    remove(fname);
    rename("temp.txt", fname);

    free(v);
    return 0;
}
