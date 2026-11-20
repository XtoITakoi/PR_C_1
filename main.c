#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    if (argc < 4 || (argc - 1) % 3 != 0) {
        printf("Пример: cmdcalc 41 + 33 111 - 8\n");
        return 1;
    }

    int count = (argc - 1) / 3;
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

    free(results);
    return 0;
}
