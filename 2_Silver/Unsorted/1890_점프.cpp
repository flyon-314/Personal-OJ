#include <iostream>
using namespace std;

int world[101][101];
long long dp[1001][1001];
int main()
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int n;
     cin>>n;

     dp[0][0] = 1;
     for (int i = 0 ; i < n ; i++)
     {
          for (int j = 0 ; j < n ; j++) cin >> world[i][j];
     }

     for (int i = 0 ; i < n ; i++)
     {
          for (int j = 0 ; j < n ; j++)
          {
               if (dp[i][j] == 0) continue;
               if (world[i][j] == 0) continue;
               
               int down = i + world[i][j];
               int right = j + world[i][j];

               if (down < n) dp[down][j] += dp[i][j];
               if (right < n) dp[i][right] += dp[i][j];
          }
     }

     cout << dp[n - 1][n - 1] << "\n";

}
