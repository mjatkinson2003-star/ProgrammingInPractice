#ifndef BUDGET_H
#define BUDGET_H

#define DEPT_NAME_LENGTH 30


void budgetMenu(void);

// report use 

int getDepartmentCount(void);
void getDepartmentName(int index, char name[]);
double getDepartmentAllocated(int index);
double getDepartmentSpent(int index);

#endif