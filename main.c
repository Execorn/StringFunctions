#include <stdio.h>
#include <malloc.h>
#include <assert.h>

int puts (const char* s) {
    assert(s != NULL);
    while (*s != '\0') {
        int check = printf("%c", *s);
        if (check < 0) {
            return check;
        }
        s++;
    }
    return printf("\n");
}

const char* strchr (const char *str, const int ch) {
    assert(str != NULL);
    assert(0 < ch && ch < 128);
    while (*str != '\0') {
        if (*str == (char) ch) {
            return str;
        }
        str++;
    }
    return NULL;
}

size_t strlen (const char *str) {
    size_t i = 0;
    while (str[i] != '\0') ++i;
    return i;
}

char* strcpy (char *destination, const char *source) {
    char* tmp = destination;
    for (size_t i = 0; source[i]; ++i) {
        destination[i] = source[i];
    }
    return tmp;
}

char* strncpy (char *destination, const char *source, size_t n) {
    char* tmp = destination;
    for (size_t i = 0; source[i] && i <= n; ++i) {
        destination[i] = source[i];
    }
    return tmp;
}

char* strcat (char *destination, const char *append) {
    char* tmp = destination;
    while (*destination) ++destination;
    while ((*destination++ = *append++));
    return tmp;
}

char* strncat (char *destination, const char *append, size_t n) {
    char* tmp = destination;
    while (*destination) ++destination;
    size_t i = 0;
    while ((*destination++ = *append++) && i <= n) ++i;
    return tmp;
}

char* strdup (const char *str) {
    char* result = malloc(sizeof(char) * strlen(str));
    if (!result) return NULL;
    strcpy(result, str);
    return result;
}

int main() {
    puts("Hello world!");
}

