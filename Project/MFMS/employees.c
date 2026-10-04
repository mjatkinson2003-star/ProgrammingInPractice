#include <stdio.h>
#include <string.h>
#include "utilities.h"
#include "employees.h"

#define MAX_EMPLOYEES 50
#define NAME_LENGTH 50
#define DEPARTMENT_LENGTH 30

// Employee data 

int empID[MAX_EMPLOYEES];
char empName[MAX_EMPLOYEES][NAME_LENGTH];
char empDepartment[MAX_EMPLOYEES][DEPARTMENT_LENGTH];
double empBasic [MAX_EMPLOYEES];
double empHousing[MAX_EMPLOYEES];
double empTransport[MAX_EMPLOYEES];
int employeeCount = 0; // Current employee count

// function decleration (used only in this .c file)

void addEmployee(void);
void displayEmployees(void);
double calculateSalary(double basic, double housing, double transport);

// Employee menu

void employeeMenu(void) {
    int choice;

    do{
        printf("\n---------------EMPLOYEE MANAGEMENT--------------\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");
        choice = readInt("Enter your choice: ", 1, 3);

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                break;
            
        }
    }while(choice != 3);
}


// emp add function

void addEmployee(void) 
{
    if(employeeCount >= MAX_EMPLOYEES){
        printf("\n Employee limit reached. Cannot add more employees.\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

    empID[employeeCount] = readInt("Employee ID: ", 1, 99999);
    readText("Full name: ", empName[employeeCount], NAME_LENGTH);
    readText("Department: ", empDepartment[employeeCount], DEPARTMENT_LENGTH);
    empBasic[employeeCount] = readDouble("Basic salary (N$): ", 0);
    empHousing[employeeCount] = readDouble("Housing allowance (N$): ", 0);
    empTransport[employeeCount] = readDouble("Transport allowance (N$): ", 0);

    employeeCount++;

    printf("\nEmployee added successfully. Total employees: %d\n", employeeCount);
}

// emp display function

void displayEmployees(void)
{
    if (employeeCount == 0) {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n%-6s %-20s %-15s %12s\n", "ID", "Name", "Department", "Gross (N$)");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < employeeCount; i++) {
        double gross = calculateSalary(empBasic[i], empHousing[i], empTransport[i]);

        printf("%-6d %-20s %-15s %12.2f\n",
               empID[i], empName[i], empDepartment[i], gross);
    }
}

// calculate salary function

double calculateSalary(double basic, double housing, double transport)
{
    return basic + housing + transport;
}