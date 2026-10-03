#include <stdio.h>

void displayMainMenu(void);

int main(void)
{
    int choice = 0;

    do {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
          case 1:
                printf("\nEmployee Management selected\n");
                break;
            case 2:
                printf("\nBudget Management selected\n");
                break;
            case 3:
                printf("\nSupplier Management selected\n");
                break;
            case 4:
                printf("\nAsset Management selected\n");
                break;
            case 5:
                printf("\nReports selected\n");
                break;
            case 6:
                printf("\nExiting MFMS. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter 1 to 6.\n");
        }

    } while (choice != 6);




    return 0;
}

void displayMainMenu(void)
{
    printf("\n========================================\n");
    printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}