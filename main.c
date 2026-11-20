#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Пример: cmdcalc 41 + 33\n");
        return 1;
    }

    int left = atoi(argv[1]);
    int right = atoi(argv[3]);
    long long result;

    if (argv[2][1] != '\0' ||
        !calculate(left, argv[2][0], right, &result)) {
        printf("Неверная операция\n");
        return 1;
    }

    printf("Ответ: %lld\n", result);
    return 0;
}
