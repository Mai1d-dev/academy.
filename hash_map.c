#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 20
#define MAX_NAME 20

typedef struct {
    char key[MAX_NAME];
    int value;
    int used;
} Entry;

unsigned int hash(const char* s) {
    unsigned int h = 0;
    while (*s)
        h = h * 31 + *s++;
    return h % TABLE_SIZE;
}

int main() {
    int n;
    printf("How many names? ");
    scanf("%d", &n);

    char* names = malloc(n * MAX_NAME * sizeof(char));
    Entry* table = calloc(TABLE_SIZE, sizeof(Entry));

    for (int i = 0; i < n; i++) {
        scanf("%19s", names + i * MAX_NAME);

        unsigned int idx = hash(names + i * MAX_NAME);

        while (table[idx].used &&
               strcmp(table[idx].key, names + i * MAX_NAME) != 0) {
            idx = (idx + 1) % TABLE_SIZE;
        }

        if (!table[idx].used) {
            strcpy(table[idx].key, names + i * MAX_NAME);
            table[idx].value = 1;
            table[idx].used = 1;
        } else {
            table[idx].value++;
        }
    }

    printf("\nResult:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].used)
            printf("%s -> %d\n", table[i].key, table[i].value);
    }

    free(names);
    free(table);
    return 0;
}
