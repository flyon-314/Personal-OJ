#include <iostream>
using namespace std;

int candy[1001][1001];
int dp[1001][1001];
int main()
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int n, m;
     cin >> n >> m;

     for (int i = 1; i <= n; i++)
     {
          for (int j = 1; j <= m; j++)
          {
               cin >> candy[i][j];
          }
     }

     for (int i = 1; i <=n; i++)
     {
          for (int j = 1; j <= m; j++)
          {
               dp[i][j] = candy[i][j];
               dp[i][j] = max(dp[i][j] + dp[i - 1][j - 1] , max(dp[i][j] + dp[i - 1][j],dp[i][j] + dp[i][j - 1]));
          }
     }

     cout << dp[n][m];
}
