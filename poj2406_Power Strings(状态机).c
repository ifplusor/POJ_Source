#include <stdio.h>
#include <string.h>


int next[1000005];
char s[1000005];

int getNext(char *p, int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
    return pLen;
}

int main() {
    while (1) {
        scanf("%s", s);
        if (s[0] == '.')
            break;
        int len = getNext(s, next);
        int n = len - next[len];  // the length of repeated element
        if (len % n == 0)
            printf("%d\n", len / n);
        else
            printf("1\n");
    }
    return 0;
}
