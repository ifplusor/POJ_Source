#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

struct Node {
    int L, R, sum; // 保存范围内节点数量
};
Node T[MAXN * 20]; // 节点池
int cursor; // 内存分配游标

int insert(int num, int pre, int L, int R) {
    // 写时复制
    int cur = cursor++; // 分配新节点
    T[cur] = T[pre]; // 复制旧子树
    T[cur].sum++;

    if(L < R) {
        int mid = (L + R) >> 1;

        if(num <= mid)
            T[cur].L = insert(num, T[cur].L, L, mid);
        else
            T[cur].R = insert(num, T[cur].R, mid+1, R);
    }

    return cur;
}

int query(int lower, int upper, int kth, int L, int R) {
    if(L == R)
        return L;

    int count = T[T[upper].L].sum - T[T[lower].L].sum;
    int mid = (R + L) >> 1;

    if(kth <= count)
        return query(T[lower].L, T[upper].L, kth, L, mid);
    else
        return query(T[lower].R, T[upper].R, kth-count, mid+1, R);
}

struct A {
    int x, idx;

    bool operator < (const A &rhs) const {
        return x < rhs.x;
    }
};

A a[MAXN]; // 带索引输入值
int alias[MAXN];
int root[MAXN]; // 线段树根
int n, m;

int main() {
    T[0].L = T[0].R = T[0].sum = 0;
    root[0] = 0;

    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].x);
            a[i].idx = i;
        }

        // 离散化，按升序赋值为 base-1 索引
        sort(a + 1, a + (n + 1));
        for(int i = 1; i <= n; ++i) {
            alias[a[i].idx] = i;
        }

        cursor = 1; // 重置分配游标
        for(int i = 1; i <= n; ++i) {
            root[i] = insert(alias[i], root[i-1], 1, n); // 插入生成新快照
        }

        while(m--) {
            int i, j, k;
            scanf("%d%d%d", &i, &j, &k);
            printf("%d\n", a[query(root[i-1], root[j], k, 1, n)].x);
        }
    }
}
