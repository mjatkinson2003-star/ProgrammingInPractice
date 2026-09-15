#include <stdio.h>
int main() {
    // variables
    float revenue;
    float expenses;
    float budget;
// title
    printf("\nMunicipality Budget Calculator\n");

// prompts
    printf("Please enter your municipality's revenue: ");
    scanf("%f",&revenue);

    printf("Please enter your municipality's expenses: ");
    scanf("%f",&expenses);
//result
    budget = revenue - expenses;
    printf("------------------------\n");
    printf("Revenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Budget: %.2f\n", budget);
    printf("------------------------\n");
return 0;
}