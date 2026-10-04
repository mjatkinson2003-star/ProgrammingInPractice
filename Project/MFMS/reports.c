#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "assets.h"
#include "reports.h"
#include "utilities.h"
#include "budget.h"

void displayAssets(void);

//interal variables
int reportChoice;

//start of employee report
//total employee display
void employeeReport(void)
{
    int count = getEmployeeCount();
    double total = 0;
    double highestSalary;
    double lowestSalary;

    printf("\n--- EMPLOYEE REPORT ---\n");

    if (count == 0) {
        printf("No employees have been added yet.\n");
        return;
    }

    highestSalary = getEmployeeGrossSalary(0);
    lowestSalary = getEmployeeGrossSalary(0);

    for (int i = 0; i < count; i++) {
        double salary = getEmployeeGrossSalary(i);

        total = total + salary;

        if (salary > highestSalary) {
            highestSalary = salary;
        }
        if (salary < lowestSalary) {
            lowestSalary = salary;
        }
    }

    printf("Total Employees : %d\n", count);
    printf("Total Salaries  : N$%.2f\n", total);
    printf("Average Salary  : N$%.2f\n", total / count);
    printf("Highest Salary  : N$%.2f\n", highestSalary);
    printf("Lowest Salary   : N$%.2f\n", lowestSalary);
}
//start of budget report
void budgetReport(void)
{
    int count = getDepartmentCount();
    double totalAllocated = 0;
    double totalSpent = 0;
    int overCount = 0;
    char name[DEPT_NAME_LENGTH];

    printf("\n--- BUDGET REPORT ---\n");

    if (count == 0) {
        printf("No departments have been added yet.\n");
        return;
    }

    // Add up the totals for all departments
    for (int i = 0; i < count; i++) {
        totalAllocated = totalAllocated + getDepartmentAllocated(i);
        totalSpent = totalSpent + getDepartmentSpent(i);
    }

    printf("Total Departments       : %d\n", count);
    printf("Total Allocated Budget  : N$%.2f\n", totalAllocated);
    printf("Total Expenditure       : N$%.2f\n", totalSpent);
    printf("Remaining Budget        : N$%.2f\n", totalAllocated - totalSpent);

    // List of exceeded departments
    printf("\nDepartments Exceeding Budget:\n");

    for (int i = 0; i < count; i++) {
        double allocated = getDepartmentAllocated(i);
        double spent = getDepartmentSpent(i);

        if (spent > allocated) {
            getDepartmentName(i, name);
            printf("  %-20s over by N$%.2f\n", name, spent - allocated);
            overCount++;
        }
    }

    if (overCount == 0) {
        printf("  None - all departments are within budget.\n");
    }
}
//start of supplier report
int supplierReport(){
    printf("Supplier report generated.\n");
    return 0;
}
//start of asset report
int assetReport(){
    printf("Asset report generating....\n");
    printf("Total assets: %d\n", assetCount);
    printf("Asset list:\n");
    displayAssets(); //display all assets in the table
    return 0;
}

void reports(){
    do {
printf("Select report you would like to generate:\n");
printf("1. Employee report\n");
printf("2. Budget report\n");
printf("3. Supplier report\n");
printf("4. Asset report\n");
printf("5. Back\n");
scanf("%d", &reportChoice);
    }while(reportChoice < 1 || reportChoice > 5);

    switch(reportChoice){
        case 1:
            employeeReport();
            break;
        case 2:
            budgetReport();
            break;
        case 3:
            supplierReport();
            break;
        case 4:
            assetReport();
            break;
        case 5:
            return;
    }


}