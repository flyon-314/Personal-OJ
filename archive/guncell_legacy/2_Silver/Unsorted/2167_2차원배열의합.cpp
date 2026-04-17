#include <iostream>

using namespace std;

int num[301][301];

int main()
{

     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     int n, m, k;
     cin >> n >> m;

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cin >> num[i][j];
          }
     }

     cin >> k;

     while (k--)
     {
          int i, j, x, y;
          int sum = 0;
          cin >> i >> j >> x >> y;

          for (int k = i - 1; k < x; k++)
          {
               for (int l = j - 1; l < y; l++)
               {
                    sum += num[k][l];
               }
          }

          cout << sum << "\n";
     }
     
}
