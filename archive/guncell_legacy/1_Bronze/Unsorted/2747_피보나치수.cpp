#include <iostream>
using namespace std;


int main()
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     int n;
     int pibo[46];
     pibo[0] = 0;
     pibo[1] = 1;
     for (int i = 2; i <= 45; i++) pibo[i] = pibo[i - 1] + pibo[i - 2];
     cin >> n;
     cout << pibo[n] << "\n";
}
