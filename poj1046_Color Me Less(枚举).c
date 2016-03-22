#include <stdio.h>
#include <math.h>

#define sqare(x) ((x) * (x))

int color[16][3];

int main()
{
    int r, g, b, i, index;
    double min, t;
    for (i = 0; i < 16; i++) {
        scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);
    }
    while (1) {
        scanf("%d %d %d", &r, &g, &b);
        if (r == -1 && g == -1 && b== -1)
            break;
        min = sqrt(sqare(r - color[0][0]) + sqare(g - color[0][1]) + sqare(b - color[0][2]));
        index = 0;
        if (min != 0) {
            for (i = 1; i < 16; i++) {
                t = sqrt(sqare(r - color[i][0]) + sqare(g - color[i][1]) + sqare(b - color[i][2]));
                if (t < min) {
                    min = t;
                    index = i;
                    if (min == 0)
                        break;
                }
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, color[index][0], color[index][1], color[index][2]);
    }
    return 0;
}
