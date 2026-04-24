//AIM: Solve matrix chain multiplication Using Dynamic Programming.

#include <stdio.h>
#include <limits.h>
int matrixChain(int p[], int n)
{
int m[100][100];
int i, j, k, L, cost; 
  for(i = 1; i < n; i++)
m[i][i] = 0;
for(L = 2; L < n; L++) {
for(i = 1; i < n - L + 1; i++)
  {
    j = i + L - 1;
m[i][j] = INT_MAX;
for(k = i; k < j; k++) {
cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
  if(cost < m[i][j])
m[i][j] = cost;
}
}
}
return m[1][n-1];
}
int main()
{
int n, i;
printf("Enter number of matrices: "); 
scanf("%d", &n);
int p[n+1];
printf("Enter the dimensions array (%d values):\n", n+1); 
  for(i = 0; i <= n; i++)
{
scanf("%d", &p[i]);
}
int result = matrixChain(p, n+1);
printf("Minimum number of multiplications required: %d\n", result); 
  return 0;
}
