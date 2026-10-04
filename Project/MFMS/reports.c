#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "assets.h"
#include "reports.h"

void displayAssets(void);

//interal variables
int reportChoice;

//start of employee report
//total employee display
int employeeReport(){
    printf("Generating employee report...\n");
      if (employeeCount == 0) {
        printf("\nNo employees have been added yet.\n");
        return 0;
    }
    printf("\nTotal employees: %d\n",employeeCount);
//highest salary calculation and display
    double highestSalary = calculateSalary(
        empBasic[0], empHousing[0], empTransport[0]
    );
    for (int i = 1; i < employeeCount; i++) {
        double salary = calculateSalary(
            empBasic[i], empHousing[i], empTransport[i]
        );
        if (salary > highestSalary) {
            highestSalary = salary;
        }
    }
    printf("Highest salary: N$ %.2f\n", highestSalary);
//lowest salary calculation and display
    double lowestSalary = calculateSalary(
        empBasic[0], empHousing[0], empTransport[0]
    );
    for (int i = 1; i < employeeCount; i++) {
        double salary = calculateSalary(
            empBasic[i], empHousing[i], empTransport[i]
        );
        if (salary < lowestSalary) {
            lowestSalary = salary;
        }
    }
    printf("Lowest salary: N$ %.2f\n", lowestSalary);


    return 0;
}
//start of budget report
int budgetReport(){
    printf("Budget report generated.\n");


    return 0;
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