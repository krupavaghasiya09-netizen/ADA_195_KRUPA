//AIM:To implement Minimun Spanning Tree(MST) problem using Kruskal’s Algorithm based on the Greedy Strategy.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Edge {
    int u, v, w;
};
int parent[100];
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}
void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->w - ((struct Edge *)b)->w;
}
int main() {
    int n, e;
    struct Edge edges[100];
    int i, count = 0;
    int totalCost = 0;
    clock_t start, end;
    double cpu_time_used;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d”, &e);
    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }
    qsort(edges, e, sizeof(struct Edge), compare);
    start = clock();
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            printf("%d -- %d == %d\n", u, v, edges[i].w);
            totalCost += edges[i].w;
            unionSet(u, v);
            count++;
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTotal cost of MST: %d\n", totalCost);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
