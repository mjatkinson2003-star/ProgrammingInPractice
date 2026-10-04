#include <stdio.h>
#include <string.h>
#include "utilities.h"
#include "budget.h"

#define MAX_DEPARTMENTS 10

// Budget data 

char deptName[MAX_DEPARTMENTS][DEPT_NAME_LENGTH];
double deptAllocated[MAX_DEPARTMENTS];
double deptSpent[MAX_DEPARTMENTS];
int departmentCount = 0; // Current department count

// Function declarations (used only in this .c file)

void addDepartment(void);
void recordExpenditure(void);
void displayBudgets(void);
void displayOverBudget(void);
void displayDepartmentSummary(int index);
int findDepartmentByName(char name[]);
int selectDepartment(void);
int isOverBudget(int index);
double calculateBudget(double allocated, double spent);

// Budget menu

void budgetMenu(void)
{
    int choice;

    do {
        printf("\n---------------BUDGET MANAGEMENT--------------\n");
        printf("1. Add Department Budget\n");
        printf("2. Record Expenditure\n");
        printf("3. Display Budget Information\n");
        printf("4. Show Departments Over Budget\n");
        printf("5. Back to Main Menu\n");
        choice = readInt("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1:
                addDepartment();
                break;
            case 2:
                recordExpenditure();
                break;
            case 3:
                displayBudgets();
                break;
            case 4:
                displayOverBudget();
                break;
            case 5:
                break;
        }
    } while (choice != 5);
}

// Add department function

void addDepartment(void)
{
    char name[DEPT_NAME_LENGTH];

    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("\nDepartment limit reached. Cannot add more departments.\n");
        return;
    }

    printf("\n--- Add Department Budget ---\n");
    do {
        readText("Department name: ", name, DEPT_NAME_LENGTH);

        if (findDepartmentByName(name) != -1) {
            printf("  Department \"%s\" already exists. Please use a different name.\n", name);
        }
    } while (findDepartmentByName(name) != -1);

    strcpy(deptName[departmentCount], name);
    deptAllocated[departmentCount] = readDouble("Allocated budget (N$): ", 0);
    deptSpent[departmentCount] = 0;   // new departments have spent nothing yet

    departmentCount++;

    printf("\nDepartment added successfully. Total departments: %d\n", departmentCount);
}

// Record expenditure function

void recordExpenditure(void)
{
    int index;
    double amount;

    if (departmentCount == 0) {
        printf("\nNo departments have been added yet.\n");
        return;
    }

    printf("\n--- Record Expenditure ---\n");

    index = selectDepartment();
    amount = readDouble("Expenditure amount (N$): ", 0.01);

    deptSpent[index] += amount;   // add to what has already been spent

    printf("\nExpenditure recorded.\n");
    displayDepartmentSummary(index);

    if (isOverBudget(index)) {
        printf("\nWARNING: %s has exceeded its allocated budget!\n", deptName[index]);
    }
}

// Display all budgets function

void displayBudgets(void)
{
    if (departmentCount == 0) {
        printf("\nNo departments have been added yet.\n");
        return;
    }

    printf("\n%-20s %14s %14s %14s  %s\n",
           "Department", "Allocated", "Spent", "Remaining", "Status");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < departmentCount; i++) {
        double remaining = calculateBudget(deptAllocated[i], deptSpent[i]);

        printf("%-20s %14.2f %14.2f %14.2f  ",
               deptName[i], deptAllocated[i], deptSpent[i], remaining);

        if (isOverBudget(i)) {
            printf("OVER BUDGET\n");
        } else {
            printf("WITHIN BUDGET\n");
        }
    }
}

// Display departments over budget function

void displayOverBudget(void)
{
    int found = 0;   // 0 = none over budget yet, 1 = at least one

    if (departmentCount == 0) {
        printf("\nNo departments have been added yet.\n");
        return;
    }

    printf("\n--- Departments Over Budget ---\n");

    for (int i = 0; i < departmentCount; i++) {
        if (isOverBudget(i)) {
            printf("%-20s over by N$%.2f\n",
                   deptName[i], deptSpent[i] - deptAllocated[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("All departments are within budget.\n");
    }
}

// Display one department's summary function

void displayDepartmentSummary(int index)
{
    double remaining = calculateBudget(deptAllocated[index], deptSpent[index]);

    printf("\nDepartment       : %s\n", deptName[index]);
    printf("Allocated Budget : N$%.2f\n", deptAllocated[index]);
    printf("Expenditure      : N$%.2f\n", deptSpent[index]);
    printf("Remaining Budget : N$%.2f\n", remaining);

    if (isOverBudget(index)) {
        printf("Status           : OVER BUDGET\n");
    } else {
        printf("Status           : WITHIN BUDGET\n");
    }
}

// Find department by name function (returns index, or -1 if not found)

int findDepartmentByName(char name[])
{
    for (int i = 0; i < departmentCount; i++) {
        if (strcmp(deptName[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

// Select department function (shows a numbered list, returns the chosen index)

int selectDepartment(void)
{
    printf("\nDepartments:\n");

    for (int i = 0; i < departmentCount; i++) {
        printf("%d. %s\n", i + 1, deptName[i]);
    }

    return readInt("Select department: ", 1, departmentCount) - 1;
}

// Over budget check function (returns 1 if over budget, 0 if not)

int isOverBudget(int index)
{
    if (deptSpent[index] > deptAllocated[index]) {
        return 1;
    }
    return 0;
}

// Calculate budget function (remaining = allocated - spent)

double calculateBudget(double allocated, double spent)
{
    return allocated - spent;
}


// FUNCTIONS FOR THE REPORTS MODULE (declared in budget.h)


// Returns how many departments are stored

int getDepartmentCount(void)
{
    return departmentCount;
}

// Copies the department name at the given index into name[]

void getDepartmentName(int index, char name[])
{
    if (index < 0 || index >= departmentCount) {
        strcpy(name, "");   // invalid index: give back an empty string
        return;
    }
    strcpy(name, deptName[index]);
}

// Returns the allocated budget at the given index (0 if invalid)

double getDepartmentAllocated(int index)
{
    if (index < 0 || index >= departmentCount) {
        return 0;
    }
    return deptAllocated[index];
}

// Returns the amount spent at the given index (0 if invalid)

double getDepartmentSpent(int index)
{
    if (index < 0 || index >= departmentCount) {
        return 0;
    }
    return deptSpent[index];
}