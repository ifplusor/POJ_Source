#include "stdio.h"
#include "stdlib.h"

int count[105];
int num[105];

int main() {
    int i, j;
    memset(count, 0, sizeof(count));
    memset(count, 0, sizeof(num));
    num[1] = 1;
    for (i = 2; i <= 100; i++) {
        for (j = i; j <= 100; j += i) {
            count[j]++;
        }
        if (count[i] % 2 == 1) {
            num[i] = num[i-1];
        } else {
            num[i] = num[i-1] + 1;
        }
    }
    scanf("%d", &i);
    while (i--) {
        scanf("%d", &j);
        printf("%d\n", num[j]);
    }
    return 0;
}
