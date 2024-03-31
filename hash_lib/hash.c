/*
** EPITECH PROJECT, 2024
** B-CPE-110-NAN-1-1-secured-albane.merian
** File description:
** hash
*/

// #include "../include/hashtable.h"

static int increse_result(char first, char new)
{
    int result = 0;
    int op = 1;

    while (first != new) {
        if (first > 127) {
            first = 0;
            op *= -1;
        }
        if (op == 1)
            result++;
        else
            result--;
        first++;
    }
    return (result * result);
}

static int hash_code(int code)
{
    int temp = 0;
    int final = 0;
    int test = 0;

    code /= 10;
    for (int i = 0; temp < 1000; i++) {
        test = code % 10;
        temp = my_compute_power_rec(10, i);
        final += test * temp;
        code /= 10;
    }
    return (final * final - code);
}

int hash(char *key, int len)
{
    int c = 0;
    int code = 0;
    char first = 0;

    while (key[c] != '\0') {
        code += increse_result(first, key[c]);
        first = key[c];
        code += key[c] * len;
        c++;
    }
    code /= len;
    code *= code;
    return hash_code(code);
}
