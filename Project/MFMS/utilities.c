#include <stdio.h>
#include <string.h>
#include "utilities.h"

/* Reads a line of text (spaces allowed) and refuses empty input */
void readText(char prompt[], char text[], int size)
{
    do {
        printf("%s", prompt);
        fgets(text, size, stdin);
        text[strcspn(text, "\n")] = '\0';   /* remove the Enter key */

        if (strlen(text) == 0) {
            printf("  This field cannot be empty. Please try again.\n");
        }
    } while (strlen(text) == 0);
}

/* Reads a whole number between min and max */
int readInt(char prompt[], int min, int max)
{
    char input[50];
    int value;
    int valid = 0;   /* 0 = not valid yet, 1 = valid */

    do {
        readText(prompt, input, sizeof(input));

        if (sscanf(input, "%d", &value) != 1) {
            printf("  Invalid input. Please enter a whole number.\n");
        } else if (value < min || value > max) {
            printf("  Please enter a number from %d to %d.\n", min, max);
        } else {
            valid = 1;
        }
    } while (valid == 0);

    return value;
}

/* Reads a decimal number that is not smaller than min */
double readDouble(char prompt[], double min)
{
    char input[50];
    double value;
    int valid = 0;

    do {
        readText(prompt, input, sizeof(input));

        if (sscanf(input, "%lf", &value) != 1) {
            printf("  Invalid input. Please enter a number.\n");
        } else if (value < min) {
            printf("  Value cannot be less than %.2f.\n", min);
        } else {
            valid = 1;
        }
    } while (valid == 0);

    return value;
}