#include <stdio.h>
#include <string.h>
#include "utilities.h"
#include "suppliers.h"

#define MAX_SUPPLIERS 50
#define SUP_NAME_LENGTH 50
#define EMAIL_LENGTH 50
#define PHONE_LENGTH 20
#define TOWN_LENGTH 30

// Supplier data (parallel arrays - same index = same supplier)

int supID[MAX_SUPPLIERS];
char supName[MAX_SUPPLIERS][SUP_NAME_LENGTH];
char supEmail[MAX_SUPPLIERS][EMAIL_LENGTH];
char supPhone[MAX_SUPPLIERS][PHONE_LENGTH];
char supTown[MAX_SUPPLIERS][TOWN_LENGTH];
int supplierCount = 0; // Current supplier count

// Function declarations (used only in this .c file)

void addSupplier(void);
void searchSupplier(void);
void displaySupplierInformation(int index);
int findSupplierByID(int id);
int isValidEmail(char email[]);
int isValidPhone(char phone[]);

// Supplier menu

void supplierMenu(void)
{
    int choice;

    do {
        printf("\n---------------SUPPLIER MANAGEMENT--------------\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                break;
        }
    } while (choice != 4);
}

// Add supplier function

void addSupplier(void)
{
    int id;

    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\nSupplier limit reached. Cannot add more suppliers.\n");
        return;
    }

    printf("\n--- Add Supplier ---\n");

    // Keep asking until the ID is not already in use
    do {
        id = readInt("Supplier ID: ", 1, 99999);

        if (findSupplierByID(id) != -1) {
            printf("  A supplier with ID %d already exists. Please use a different ID.\n", id);
        }
    } while (findSupplierByID(id) != -1);

    supID[supplierCount] = id;
    readText("Supplier name: ", supName[supplierCount], SUP_NAME_LENGTH);

    // Keep asking until the email looks valid
    do {
        readText("Email: ", supEmail[supplierCount], EMAIL_LENGTH);

        if (isValidEmail(supEmail[supplierCount]) == 0) {
            printf("  Invalid email. It must contain one '@' and a '.' (e.g. sales@abc.com).\n");
        }
    } while (isValidEmail(supEmail[supplierCount]) == 0);

    // Keep asking until the phone number looks valid
    do {
        readText("Telephone number: ", supPhone[supplierCount], PHONE_LENGTH);

        if (isValidPhone(supPhone[supplierCount]) == 0) {
            printf("  Invalid phone number. Use digits only, 7 to 15 digits (e.g. 0811234567).\n");
        }
    } while (isValidPhone(supPhone[supplierCount]) == 0);

    readText("Town/Location: ", supTown[supplierCount], TOWN_LENGTH);

    supplierCount++;

    printf("\nSupplier added successfully. Total suppliers: %d\n", supplierCount);
}

// Display all suppliers

void displaySuppliers(void)
{
    if (supplierCount == 0) {
        printf("\nNo suppliers have been added yet.\n");
        return;
    }

    printf("\n%-6s %-25s %-13s %-15s %s\n", "ID", "Name", "Phone", "Town", "Email");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < supplierCount; i++) {
        printf("%-6d %-25s %-13s %-15s %s\n",
               supID[i], supName[i], supPhone[i], supTown[i], supEmail[i]);
    }
}

// Search supplier function

void searchSupplier(void)
{
    int option;

    if (supplierCount == 0) {
        printf("\nNo suppliers have been added yet.\n");
        return;
    }

    printf("\n--- Search Supplier ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Town\n");
    option = readInt("Enter your choice: ", 1, 3);
    //ID
    if (option == 1) {
        int id = readInt("Enter Supplier ID: ", 1, 99999);
        int index = findSupplierByID(id);

        if (index == -1) {
            printf("\nNo supplier found with ID %d.\n", id);
        } else {
            displaySupplierInformation(index);
        }
    //NAME
    } else if (option == 2) {
        char searchName[SUP_NAME_LENGTH];
        int found = 0;   // 0 = no match, 1 = at least one match

        readText("Enter supplier name: ", searchName, SUP_NAME_LENGTH);

        for (int i = 0; i < supplierCount; i++) {
            if (strcmp(supName[i], searchName) == 0) {
                displaySupplierInformation(i);
                found = 1;
            }
        }

        if (found == 0) {
            printf("\nNo supplier found with the name \"%s\".\n", searchName);
        }
    } else {
        char searchTown[TOWN_LENGTH];
        int found = 0;

        readText("Enter town: ", searchTown, TOWN_LENGTH);

        for (int i = 0; i < supplierCount; i++) {
            if (strcmp(supTown[i], searchTown) == 0) {
                displaySupplierInformation(i);
                found = 1;
            }
        }

        if (found == 0) {
            printf("\nNo suppliers found in \"%s\".\n", searchTown);
        }
    }
}

// Display one supplier's details function

void displaySupplierInformation(int index)
{
    char description[150];

    // Builds a description
    strcpy(description, supName[index]);
    strcat(description, " operates in ");
    strcat(description, supTown[index]);
    strcat(description, ".");

    printf("\n--- Supplier Found ---\n");
    printf("Supplier ID : %d\n", supID[index]);
    printf("Name        : %s\n", supName[index]);
    printf("Email       : %s\n", supEmail[index]);
    printf("Telephone   : %s\n", supPhone[index]);
    printf("Town        : %s\n", supTown[index]);
    printf("Summary     : %s\n", description);
}

// Find supplier by ID function (returns index, or -1 if not found)

int findSupplierByID(int id)
{
    for (int i = 0; i < supplierCount; i++) {
        if (supID[i] == id) {
            return i;
        }
    }
    return -1;
}

// Email check function (returns 1 if valid, 0 if not)
// Rule: exactly one '@', not at the start, and at least one '.'

int isValidEmail(char email[])
{
    int length = strlen(email);
    int atCount = 0;
    int dotFound = 0;

    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atCount++;
        }
        if (email[i] == '.') {
            dotFound = 1;
        }
    }

    if (atCount == 1 && dotFound == 1 && email[0] != '@') {
        return 1;
    }
    return 0;
}

// Phone check function (returns 1 if valid, 0 if not)
// Rule: 7 to 15 characters, digits only

int isValidPhone(char phone[])
{
    int length = strlen(phone);

    if (length < 7 || length > 15) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;   // found a character that is not a digit
        }
    }
    return 1;
}


// FUNCTIONS FOR THE REPORTS MODULE (declared in suppliers.h)


// Returns how many suppliers are stored

int getSupplierCount(void)
{
    return supplierCount;
}