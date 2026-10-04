# Municipal Financial Management System (MFMS)

PAP521S – Programming in Practice | Project A

## Group Number

Part-Time practical group 2

## Group Members

| Name | Student Number |
|------|----------------|
| MJ Atkinson | 226012344 |
| Rayden Etsebeth | 223032379 |

## Project Description

A municipality has to keep track of its employees and their salaries, the budget allocated to each department, the suppliers it buys from, and the assets it owns. Doing this by hand or in scattered spreadsheets makes it slow to find information and easy to make calculation errors.So our group created The Municipal Financial Management System (MFMS) is a menu-driven C program that helps a municipality manage its employees, departmental budgets, suppliers and assets, and produce summary reports.


## System Features

### Employee Management
- Add employees (ID, name, department, basic salary, housing and transport allowances)
- Display all employees with their gross salary
- Search employees by ID or by name
- Salary information: gross salary, tax, net salary and income class
- Prevents duplicate employee IDs

### Budget Management
- Add departments with an allocated budget
- Record expenditure against a department
- Calculate the remaining budget and show WITHIN BUDGET / OVER BUDGET status
- List departments that have exceeded their budget
- Prevents duplicate department names

### Supplier Management
- Add suppliers (ID, name, email, telephone, town)
- Display all suppliers
- Search suppliers by ID, name or town
- Validates email addresses and telephone numbers

### Asset Management
- [Partner to fill in]

### Reports
- Employee report: total employees, total, average, highest and lowest salary
- Budget report: total allocated, total expenditure, remaining budget, departments over budget
- Supplier report: all registered suppliers
- Asset report: [partner to fill in]

### Input Validation
- Invalid menu choices are rejected
- Negative salaries, budgets and amounts are rejected
- Empty text fields are rejected
- Letters entered where numbers are expected are rejected

## Project Structure

| File | Purpose |
|------|---------|
| `main.c` | Main menu and program flow |
| `utilities.c / .h` | Shared input and validation functions (`readText`, `readInt`, `readDouble`) |
| `employees.c / .h` | Employee Management module |
| `budget.c / .h` | Budget Management module |
| `suppliers.c / .h` | Supplier Management module |
| `assets.c / .h` | Asset Management module |
| `reports.c / .h` | Reports module |

## Compilation Instructions

Requires the GCC compiler.

From inside the `MFMS` folder, run:

```
gcc -std=c99 -Wall main.c utilities.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
```

## How to Run

macOS / Linux:

```
./mfms
```

Windows:

```
mfms.exe
```

Use the number keys to choose menu options and press Enter.

## Individual Responsibilities

| Member | Responsibilities |
|--------|------------------|
| MJ Atkinson | Employee Management, Budget Management, Supplier Management, report getter functions, Testing(Shared), main menu (shared) |
| Rayden Etsebeth | Asset Management, Reports,Technical Report, input utilities, Testing(shared), main menu (shared) |

## Known Limitations

- Data is stored in memory only and is lost when the program closes (file storage planned for Project B).
- Name and town searches are case-sensitive and require an exact match.
- Tax rates are simplified values chosen by the group, not official Namibian PAYE tables.