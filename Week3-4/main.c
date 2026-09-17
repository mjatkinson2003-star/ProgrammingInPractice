
// // Salary Calculator
// #include <stdio.h>
// int main()
// {
//     float basicSalary;
//     float housing;
//     float transport;
//     float tax;
//     float grossSalary;
//     float netSalary;

//     printf("Enter basic salary: ");
//     scanf("%f", &basicSalary);

//     printf("Enter housing allowance: ");
//     scanf("%f", &housing);

//     printf("Enter transport allowance: ");
//     scanf("%f", &transport);

//     printf("Enter tax: ");
//     scanf("%f", &tax);

//     grossSalary = basicSalary + housing + transport;
//     netSalary = grossSalary - tax;

//     printf("\nGross Salary: %.2f\n", grossSalary);
//     if (netSalary >= 20000){
//         printf("Net Salary - High Income: %.2f\n", netSalary);
//     }
//     else{
//         printf("Net Salary - Standard Income: %.2f\n", netSalary);
//     }

//     return 0;
// }


// lab2

#include <stdio.h>
int main() {
  // variables
char studentName[50];
float test1;
float test2;
float assignment;
float average;

printf("\nStudent Grade Calculator\n");
// prompts
printf("Please enter the student's name: ");
scanf("%49s", studentName);
printf("Please enter the score for Test 1: ");
scanf("%f", &test1);
printf("Please enter the score for Test 2: ");
scanf("%f", &test2);
printf("Please enter the score for the Assignment: ");
scanf("%f", &assignment);

average = (test1 + test2 + assignment) / 3;
printf("------------------------\n");
if (average >= 75) {
    printf("Student Name: %s\n", studentName);
    printf("Average Score: %.2f\n", average);
    printf("Destinction\n");
}
else if(average >= 60 && average < 75) {
    printf("Student Name: %s\n", studentName);
    printf("Average Score: %.2f\n", average);
    printf("Credit\n");
}
else if(average >= 50 && average < 60) {
    printf("Student Name: %s\n", studentName);
    printf("Average Score: %.2f\n", average);
    printf("Pass\n");
}
else {
    printf("Student Name: %s\n", studentName);
    printf("Average Score: %.2f\n", average);
    printf("Fail\n");
}
printf("------------------------\n");
  return 0;
}