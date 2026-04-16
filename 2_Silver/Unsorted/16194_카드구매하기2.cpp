#include <iostream>
using namespace std;

int card[1001];
int main()
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int n;
     cin >> n;

     card[0] = 100000;
     for (int i = 1 ; i <= n ; i++)
     {
          int inp;
          cin >> inp;

          card[i] = inp;

          for (int j = 1 ; j < i ; j++)
          {
               card[i] = min(card[i], card[i - j] + card[j] );
          }
     }

     cout << card[n];
     
}
