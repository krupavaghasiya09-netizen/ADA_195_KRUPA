//AIM:To implement Minimun Spanning Tree(MST) problem using Prim’s Algorithm based on the Greedy Strategy.

#include <stdio.h>
#include <limits.h>
#include <time.h>
int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
           int selected[n], key[n], parent[n];
            for(int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        selected[i] = 0; }
 clock_t start = clock();
    key[0] = 0;
    parent[0] = -1;
for(int count = 0; count < n - 1; count++){
  int min = INT_MAX, u;
   for(int v = 0; v < n; v++)
           if(selected[v] == 0 && key[v] < min){
           min = key[v];
                u = v; }
        selected[u] = 1;
         for(int v = 0; v < n; v++)
            if(graph[u][v] && selected[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v]; }
    }
 clock_t end = clock();
 printf("\nEdge \tWeight\n");
    for(int i = 1; i < n; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
       double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nExecution Time: %f seconds\n", time);
return 0;
}
