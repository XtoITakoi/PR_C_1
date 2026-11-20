#include <stdio.h>
#include "calc.h"

int calculate(int left, char operation, int right, long long *result)
{
    switch (operation) {
        case '+':
            *result = (long long)left + right;
            break;
        case '-':
            *result = (long long)left - right;
            break;
        case '*':
            *result = (long long)left * right;
            break;
        case '%':
            if (right == 0) {
                return 0;
            }
            *result = (long long)left % right;
            break;
        default:
            return 0;
    }
    return 1;
}

void printText(const long long *results, int count, int key)
{
    printf("Результирующая строка: ");
    for (int i = 0; i < count; ++i) {
        printf("%c", (char)(results[i] - key));
    }
    printf("\n");
}
