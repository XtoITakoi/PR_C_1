#include "calc.h"

long long calculate(int left, char operation, int right)
{
    switch (operation) {
        case '+': return (long long)left + right;
        case '-': return (long long)left - right;
        case '*': return (long long)left * right;
        default: return 0;
    }
}
