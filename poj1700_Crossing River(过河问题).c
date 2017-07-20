#include <stdio.h>
#include <stdlib.h>

int cost[1005];

int cmp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int T, N, i, t, k, l, total;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%d", cost+i);
		}
		if (N == 0) {
			printf("0\n");
		} else if (N == 1) {
			printf("%d\n", cost[0]);
		} else {
			qsort(cost, N, sizeof(int), cmp);
			total = 0;
			while (N > 3) {
				if (2*cost[1] < cost[0]+cost[N-2]) {
					total += cost[0] + 2*cost[1] + cost[N-1];
				} else {
					total += 2*cost[0] + cost[N-2] + cost[N-1];
				}
				N -= 2;
			}
			if (N == 3)
				total += cost[2] + cost[0];
			total += cost[1];
			printf("%d\n", total);
		}
	}
	return 0;
}
