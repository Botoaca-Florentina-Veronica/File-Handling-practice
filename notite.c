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
