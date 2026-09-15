#include <stdio.h>
int main() {
    // variables
    char municipalityName[50];
    char mayorName[50];
    int population;

// welcome message
    printf("\nMunicipality Financial Management System\n");
    printf("\nWelcome to Windhoek Municipality\n\n");
// prompts
    printf("Please enter your municipality name: ");
    scanf("%49s",municipalityName);

    printf("Please enter your mayor's name: ");
    scanf("%49s",mayorName);

    printf("Please enter your municipality's population: ");
    scanf("%d",&population);


    // report
printf("----------------------------------------\n");
printf("Municipality Name: %s\n", municipalityName);
printf("Mayor's Name: %s\n", mayorName);
printf("Population: %d\n", population);
printf("----------------------------------------\n");


    return 0;
}