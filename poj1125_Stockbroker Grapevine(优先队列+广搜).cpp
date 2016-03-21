#include <stdio.h>
#include <memory.h>
#include <queue>

using namespace std;

struct node {
    int count;
    int contacts[105][2];
} sbs[105];
int visited[105];

class P {
public:
    int sb, time;

    P(int sb, int time):sb(sb),time(time) { }

    bool operator< (const P &b) const
    {
        return time > b.time;
    }
};


int main()
{
    int node_num;
    for(;;) {
        scanf("%d", &node_num);
        if (node_num == 0)
            break;
        for(int i = 1; i <= node_num; i++) {
            scanf("%d", &sbs[i].count);
            for (int j = 0; j < sbs[i].count; j++) {
                scanf("%d %d", &sbs[i].contacts[j][0], &sbs[i].contacts[j][1]);
            }
        }


        int minTime = 10000, minSb;

        for (int i = 1; i <= node_num; i++) {
            int visiting = node_num;
            int time = 0;
            memset(visited, 0, sizeof(visited));
            priority_queue<P> pqueue;

            pqueue.push(P(i, 0));
            while (visiting && !pqueue.empty()) {
                P t = pqueue.top();
                pqueue.pop();
                int sb = t.sb;
                if (!visited[sb]) {
                    time = t.time;
                    visited[sb] = 1;
                    visiting--;

                    for (int j = 0; j < sbs[sb].count; j++) {
                        if (!visited[sbs[sb].contacts[j][0]]) {
                            pqueue.push(P(sbs[sb].contacts[j][0], time + sbs[sb].contacts[j][1]));
                        }
                    }
                }
            }

            if (!visiting && time < minTime) {
                minTime = time;
                minSb = i;
            }
        }
        if (minTime != 10000) {
            printf("%d %d\n", minSb, minTime);
        } else {
            printf("disjoint\n");
        }
    }
    return 0;
}
