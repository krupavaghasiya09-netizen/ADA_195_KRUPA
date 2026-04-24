//AIM: - Solve Make a change problem Using Dynamic Programming.

#include <stdio.h>
#include <limits.h>
#include <time.h>
int minCoins(int coins[], int n, int amount)
{
    int dp[amount + 1];
   dp[0] = 0;
    for(int i = 1; i <= amount; i++)
     dp[i] = INT_MAX;
   for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < n; j++){
            if(coins[j] <= i && dp[i - coins[j]] != INT_MAX){
                if(dp[i] > dp[i - coins[j]] + 1)
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }
 if(dp[amount] == INT_MAX)
        return -1;
    else
        return dp[amount];
}
int main() {
    int n, amount;
   printf("Enter number of coins: ");
    scanf("%d", &n);

    int coins[n];
    printf("Enter coin values:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    printf("Enter amount: ");
    scanf("%d", &amount);
   clock_t start, end;
   start = clock();   
   int result = minCoins(coins, n, amount);
   end = clock();    
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  if(result == -1)
        printf("Change not possible\n");
    else
        printf("Minimum coins required = %d\n", result);
   printf("Execution time = %f seconds\n", time_taken);
 return 0;
}
