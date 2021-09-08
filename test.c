#include <stdio.h>
#include <malloc.h>
#include "my_stdlib.h"


size_t StrLenTest() {
    return strlen("This string is 29 char's long") == 29;
}

size_t StrChrTest() {
    return *strchr("1234567890", '7') == '7';
}

size_t PutsTest() {
    int check = puts("Hello world!");   // nothing to test
    return check == 1;
}

size_t StrCpyTest() {
    char dest[6] = "";
    char arr[6] = "hello";
    strcpy(dest, arr);
    return !strcmp(dest, arr);
}

size_t StrnCpyTest() {
    char dest[4] = "";
    char arr[6] = "hello";
    strncpy(dest, arr, 3);
    return !strcmp(dest, "hel");
}

size_t StrCatTest() {
    char dest[12] = "hello";
    char append[6] = "world";
    strcat(dest, append);
    return !strcmp(dest, "helloworld");
}

size_t StrnCatTest() {
    char dest[9] = "hello";
    char append[6] = "world";
    strncat(dest, append, 3);
    return !strcmp(dest, "hellowor");
}

size_t StrDupTest() {
    char str[8] = "welcome";
    char* newstr = strdup(str);
    int a = !strcmp(str, newstr);
    free(newstr);
    return a;
}

/*!
 * \brief Функция выполнения юнит тестирования.
 *
 * Создает переменную подсчета количества верно выполненных тестов и выводит в поток
 * stdout сообщение об успешном завершении всех тестов. Если какой-либо тест не прошел, функция выведет
 * сообщение об ошибке.
 *
 */

void UnitTest() {
    size_t success_count = 0;

    size_t (*tests[])() = {StrCatTest, StrChrTest, StrLenTest, StrnCpyTest, StrCpyTest,
                           StrDupTest, StrnCatTest, PutsTest};

    for (int i = 0; i < 8; ++i) {
        printf("starting test %d\n", i + 1);
        size_t check = tests[i]();
        success_count += check;
        printf("running test %d, it's %s \n \n", i + 1, check ? "ok" : "fail");
    }

    printf("%zu of 8 tests completed successfully. \n", success_count);
}

int main() {
    UnitTest();
}

