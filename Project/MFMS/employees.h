#ifndef EMPLOYEES_H
#define EMPLOYEES_H

extern int employeeCount;//extern added for reports
extern double empBasic[];
extern double empHousing[];
extern double empTransport[];

void employeeMenu(void);
double calculateSalary(double basic, double housing, double transport);// added for reports


#endif