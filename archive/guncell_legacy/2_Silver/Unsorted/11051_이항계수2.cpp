#include <iostream>
using namespace std;

int num[1002][1002];
int main()
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int n, m;
     cin >> n >> m;

     for (int i = 0 ; i <= n ; i++)
     {
          num[i][0] = 1;
          num[i][i] = 1;
     }
     for (int i = 2 ; i <= n ; i++)
     {
          for (int j = 1; j <= i; j++)
          {
               num[i][j] = (num[i - 1][j - 1] + num[i - 1][j]) % 10007;
          }
     }

     cout << num[n][m] ;
     
     
     
}
