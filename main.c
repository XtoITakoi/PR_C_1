#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    if (argc < 6 || (argc - 3) % 3 != 0) {
        printf("Пример: cmdcalc 41 + 33 111 - 8 -k 2\n");
        return 1;
    }

    if (argv[argc - 2][0] != '-' || argv[argc - 2][1] != 'k' ||
        argv[argc - 2][2] != '\0') {
        printf("Нужен флаг -k\n");
        return 1;
    }

    int key = atoi(argv[argc - 1]);
    int count = (argc - 3) / 3;
    long long *results = malloc((size_t)count * sizeof(long long));
    if (results == NULL) {
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        int p = 1 + 3 * i;
        int left = atoi(argv[p]);
        int right = atoi(argv[p + 2]);

        if (argv[p + 1][1] != '\0' ||
            !calculate(left, argv[p + 1][0], right, &results[i])) {
            printf("Ошибка в выражении %d\n", i + 1);
            free(results);
            return 1;
        }
    }

    for (int i = 0; i < count; ++i) {
        printf("Ответ №%d: %lld\n", i + 1, results[i]);
    }

    printText(results, count, key);
    free(results);
    return 0;
}
