#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a person
typedef struct Person
{
    char name[50];
    char id[10];
} Person;

// Bubble sort function for sorting by ID in ascending order
void sortByID(Person people[], int n)
{
    int i,j;
    for (i=0; i<n-1; i++)
        {
        for (j=0; j<n-i-1; j++)
            {
            if (strcmp(people[j].id, people[j+1].id) > 0)
            {
                // Swap the two people
                Person temp = people[j];
                people[j] = people[j+1];
                people[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    // Open the input file for reading
    FILE *f1 = fopen("verasmechera.txt", "r");
    if (f1 == NULL)
    {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Read the list of people from the input file into an array of Person structs
    Person people[100];
    int i, n = 0;
    char line[62]; // 2 for the space and newline characters
    while (fgets(line, sizeof(line), f1) != NULL)
        {
        if (fscanf(f1, "%s %s", people[n].name, people[n].id) != 2)
        {
            printf("Invalid input line: %s\n", line);
            continue;
        }
        n++;
    }

    // Close the input file
    fclose(f1);

    // Sort the list of people in ascending order by ID
    sortByID(people, n);

    // Print the sorted list of people to the console
    for (i=0; i<n; i++)
    {
        printf("%s %s\n", people[i].id, people[i].name);
    }
    return 0;
}
