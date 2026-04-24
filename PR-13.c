//AIM:Solve Shortest Common Supper sequence (SCS) using Dynamic Programming.

#include <stdio.h>
#include <string.h>
int main() {
    char s1[100], s2[100];
    int dp[100][100];
   printf("Enter first string: ");
    scanf("%s", s1);
   printf("Enter second string: ");
    scanf("%s", s2);
   int m = strlen(s1);
    int n = strlen(s2);
    
for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else {
                if (dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
 }
    }
    int i = m, j = n;
    char scs[200];
    int k = 0;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            scs[k++] = s1[i-1];
            i--; j--;
        } 
else if (dp[i-1][j] > dp[i][j-1]) {
            scs[k++] = s1[i-1];
            i--;
        }
  else
 {
            scs[k++] = s2[j-1];
            j--;
        }
    }
while (i > 0) {
        scs[k++] = s1[i-1];
        i--;
    }
while (j > 0) {
        scs[k++] = s2[j-1];
        j--;
    }
scs[k] = '\0';
    for (int x = 0; x < k/2; x++) {
        char temp = scs[x];
        scs[x] = scs[k-x-1];
        scs[k-x-1] = temp;
    }
printf("Shortest Common Supersequence = %s\n", scs);
  return 0;
}
