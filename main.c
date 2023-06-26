#include <stdio.h>
#include <stdlib.h>

struct ESPer {
    char name[64];
    int level;
};

// I couldn't understand this at first, so I redid the bubble sort
int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void sort_level(struct ESPer *arr, const int length) {
    int temp_num;
    char temp_name[64];
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j].level > arr[i].level) {
                temp_num = arr[j].level;
                for (int k = 0; k < 64; ++k) {
                    temp_name[k] = arr[j].name[k];
                }
                arr[j].level = arr[i].level;
                for (int k = 0; k < 64; ++k) {
                    arr[j].name[k] = arr[i].name[k];
                }
                arr[i].level = temp_num;
                for (int k = 0; k < 64; ++k) {
                    arr[i].name[k] = temp_name[k];
                }
            }
        }
    }
}

int main() {
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }

    sort_level(tokiwadai, n);

    for (int i = 0; i < n; ++i) {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }

    return 0;
}