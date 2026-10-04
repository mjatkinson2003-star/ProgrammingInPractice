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
void searchEmployee(void);
void salaryInformation(void);
void displayEmployeeInformation(int index);
int findEmployeeByID(int id);
double calculateSalary(double basic, double housing, double transport);
double calculateTax(double grossSalary);

// Employee menu

void employeeMenu(void) {
    int choice;

    do{
        printf("\n---------------EMPLOYEE MANAGEMENT--------------\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Salary Information\n");
        printf("5. Back to Main Menu\n");
        choice = readInt("Enter your choice: ", 1, 5);

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                salaryInformation();
                break;
            case 5:
                break;
            
        }
    }while(choice != 5);
}


// emp add function

void addEmployee(void) 
{
    int id;
    if(employeeCount >= MAX_EMPLOYEES){
        printf("\n Employee limit reached. Cannot add more employees.\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

  do {
    id = readInt("Employee ID: ", 1, 99999);

    if (findEmployeeByID(id) != -1) {
        printf("  An employee with ID %d already exists. Please use a different ID.\n", id);
    }
    } while (findEmployeeByID(id) != -1);
    empID[employeeCount] = id;
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

// search employee

void searchEmployee(void)
{
    int option;

    if (employeeCount == 0) {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n--- Search Employee ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    option = readInt("Enter your choice: ", 1, 2);

    // ID search
    if (option == 1) {
        int id = readInt("Enter Employee ID: ", 1, 99999);
        int index = findEmployeeByID(id);

        if (index == -1) {
            printf("\nNo employee found with ID %d.\n", id);
        } else {
            displayEmployeeInformation(index);
        }
    } else{
    // Name search
    char searchName[NAME_LENGTH];
        int found = 0;   /* 0 = no match yet, 1 = at least one match */

        readText("Enter full name: ", searchName, NAME_LENGTH);

        for (int i = 0; i < employeeCount; i++) {
            if (strcmp(empName[i], searchName) == 0) {
                displayEmployeeInformation(i);
                found = 1;
            }
        }

        if (found == 0) {
            printf("\nNo employee found with the name \"%s\".\n", searchName);
        }
    }
}



// salary information function (for one employee)

void salaryInformation(void)
{
    int id;
    int index;
    double gross;
    double tax;
    double net;

    if (employeeCount == 0) {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    id = readInt("\nEnter Employee ID: ", 1, 99999);
    index = findEmployeeByID(id);

    if (index == -1) {
        printf("\nNo employee found with ID %d.\n", id);
        return;
    } 

    gross = calculateSalary(empBasic[index], empHousing[index], empTransport[index]);
    tax = calculateTax(gross);
    net = gross - tax;

    printf("\n--- Salary Information: %s  ---\n", empName[index]);
    printf("Basic Salary            : N$%12.2f\n", empBasic[index]);
    printf("Housing Allowance       : N$%12.2f\n", empHousing[index]);
    printf("Transport Allowance     : N$%12.2f\n", empTransport[index]);
    printf("Gross Salary            : N$%12.2f\n", gross);
    printf("Tax                     : N$%12.2f\n", tax);
    printf("Net Salary              : N$%12.2f\n", net);

    if (net>= 20000){
        printf("Income Class               : High Income\n");
    } else{
        printf("Income Class               : Standard Income\n");
    }
}


//display one employee details function

void displayEmployeeInformation(int index)
{
    double gross = calculateSalary(empBasic[index], empHousing[index], empTransport[index]);

    printf("\n--- Employee Found ---\n");
    printf("Employee ID  : %d\n", empID[index]);
    printf("Name         : %s\n", empName[index]);
    printf("Department   : %s\n", empDepartment[index]);
    printf("Gross Salary : N$%.2f\n", gross);
}


//find employee by ID function

int findEmployeeByID(int id)
{
    for (int i = 0; i < employeeCount; i++) {
        if (empID[i] == id) {
            return i;
        }
    }
    return -1;
}

// calculate salary function

double calculateSalary(double basic, double housing, double transport)
{
    return basic + housing + transport;
}

// calculate tax function

double calculateTax(double grossSalary)
{
    if (grossSalary <= 10000) {
        return 0; 
    } else if (grossSalary <= 25000) {
        return grossSalary * 0.18; 
    } else {
        return grossSalary * 0.25; 
    }
}

// how many employees (report use)
int getEmployeeCount(void)
{
    return employeeCount;
}

// get gross salary (report use)
double getEmployeeGrossSalary(int index){
    if (index < 0 || index >= employeeCount) {
        return 0; // Invalid index
    }
    return calculateSalary(empBasic[index], empHousing[index], empTransport[index]);
}