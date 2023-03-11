/*

//prb 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
      char s[100];   //s reprezinta cuvantul
      printf("Introduceti un sir de caractere: ");
      fgets(s, 100, stdin);
      printf("Hello %s !", s);
      return 0;
}

*/


/*
//prb 2
#include<stdio.h>
#include<string.h>
#include<stdint.h>

int functie(int n)
{
    int i, k=0;
    uint8_t mask=0x80;
    uint8_t b=0;
    for(i=0; i<8; i++)
    {
        b= mask & n;
        if(b!=0)
        {
            k++;
        }
        mask = mask >>1;
    }
    return k;
}
int main(void)
{
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    printf("Numarul de biti de 1 este: %d\n", functie(n));
    return 0;
}

//prb 3
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
void afisare_pe_biti(uint16_t n)
{
    uint16_t mask=0x8000;
    uint8_t i=0;
    for(i=0; i<16; i++)
    {
        if((n & mask)==0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
        mask=mask>>1;
    }
    printf("\n");
}


int main(void)
{
    int i, n;
    char s[100], *d;
    printf("Introduceti un sir de caractere: ");
    fgets(s, 100, stdin);
    n=strlen(s);
    d=(char *)malloc(n*sizeof(char));
    if(d==NULL)
    {
        printf("Eroare!!!!");
        exit(-1);
    }
    for(i=0; i<n; i++)
    {
        d[i]=s[i]; //copiere
    }
    afisare_pe_biti(n);
    return 0;
}

//prb 4
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct
 {
    char nume[20];
    char marca[20];
    char cod[20];
    int pret;
 }Unelte;

int 


 int main(void)
 {
    int n;
    printf("Adauga o optiune: ");
    scanf("%d", &n);
    switch(n)
    {
        case 0:
        {
            break;
        }
        case 1:
        {

        }
    }
 }

*/

/*
//Afisati toate cuvintele dintr-un fisier cu prima litera fiind majuscula
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void functie_majuscula(char ch[100])
{
    if(islower(ch[0]))
    {
        ch[0]=toupper(ch[0]);
        printf("%c", ch[0]);
    }
    int i, n;
    n=strlen(ch);
    for(i=1; i<n; i++)
    {
        if(ch[i-1]==' ' && islower(ch[i]))
        {
            ch[i]=toupper(ch[i]);
            printf("%c", ch[i]);
            
        }
        else
        {
            printf("%c", ch[i]);
        }
    }
    
}

int main(void)
{
    FILE *f1;
    char ch[100];
    char fname[40]="verasmechera.txt";
    f1=fopen(fname, "r+");
    if(f1==NULL)
    {
        printf("Eroare!!!");
        exit(-1);
    }
    while(fgets(ch, 100, f1) != NULL)
    {
        functie_majuscula(ch);
    }
    printf("\n");
    return 0;
}

*/




//sort in ascending order the ids and alphabetical order the names of people in a txt file using struct, and print the result on the compiler too
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10
#define MAX_PEOPLE 100

// Define a struct to represent a person
typedef struct Person {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
} Person;

// Bubble sort function for sorting by ID in ascending order
void sortByID(Person people[], int numPeople) {
    for (int i = 0; i < numPeople - 1; i++) {
        for (int j = 0; j < numPeople - i - 1; j++) {
            if (strcmp(people[j].id, people[j+1].id) > 0) {
                // Swap the two people
                Person temp = people[j];
                people[j] = people[j+1];
                people[j+1] = temp;
            }
        }
    }
}

// Bubble sort function for sorting by name in alphabetical order
void sortByName(Person people[], int numPeople) {
    for (int i = 0; i < numPeople - 1; i++) {
        for (int j = 0; j < numPeople - i - 1; j++) {
            if (strcmp(people[j].id, people[j+1].id) == 0 && strcmp(people[j].name, people[j+1].name) > 0) {
                // Swap the two people
                Person temp = people[j];
                people[j] = people[j+1];
                people[j+1] = temp;
            }
        }
    }
}

int main() {
    // Open the input file for reading
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Read the list of people from the input file into an array of Person structs
    Person people[MAX_PEOPLE];
    int numPeople = 0;
    char line[MAX_NAME_LENGTH + MAX_ID_LENGTH + 2]; // 2 for the space and newline characters
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        if (sscanf(line, "%s %s", people[numPeople].name, people[numPeople].id) != 2) {
            printf("Invalid input line: %s\n", line);
            continue;
        }
        numPeople++;
    }

    // Close the input file
    fclose(inputFile);

    // Sort the list of people in ascending order by ID
    sortByID(people, numPeople);

    // Sort the list of people in alphabetical order by name within each group of the same ID
    int startIndex = 0;
    for (int i = 1; i <= numPeople; i++) {
        if (i == numPeople || strcmp(people[i].id, people[startIndex].id) != 0) {
            sortByName(&people[startIndex], i - startIndex);
            startIndex = i;
        }
    }

    // Print the sorted list of people to the console
    for (int i = 0; i < numPeople; i++) {
        printf("%s %s\n", people[i].id, people[i].name);
    }

    return 0;
}









//C program that capitalize every word in a file and prints it on the screen. 
//Use a function for capitalizing.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(void)
{
    int i, n=0;
    char ch, fname[40]="verasmechera.txt";
    FILE *f1, *f2;
    f1=fopen(fname, "r");
    f2=fopen("temp.txt", "w");
    if(f1==NULL && f2==NULL)
    {
        printf("Eroare fisiere!!");
        exit(1);
    }
    while((ch=fgetc(f1))!=EOF)
    {
        printf("%c", ch);  //printam elementele pe ecran
        n++;  //numaram sa vedem cate caractere avem in fisier

        if(ch>=97 && ch<=122)
        {
            ch=toupper(ch);
        }

        for(i=0; i<n; i++)
        {
            if(ch==' ')
            {
                ch=toupper(ch);
            }
        }
    }
    while((ch=fgetc(f1))!=EOF)
    {
        fprintf(f2, "%c", ch);
    }

    fclose(f1);
    fclose(f2);


    remove(fname);
    rename("temp.txt", fname);

    f2=fopen(fname, "r");
    if(f2==NULL)
    {
        printf("Eroare fisier");
        exit(1);
    }

    while((ch=fgetc(f2))!=EOF)
    {
        printf("%c", ch);
    }

    fclose(f2);
    return 0;
}
