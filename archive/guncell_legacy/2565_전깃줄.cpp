#include <algorithm>
#include <ios>
#include <iostream>

using namespace std;
#include <stdio.h>
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int line[2][501] = {0};
    int dp[101] = {0};
    int n;
    int count = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        count = max(count, max(a, b));
        line[0][a] = b ;
        line[1][b] = a;
    }
    
    for (int i = 0 ; i <= count; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (line[1][j] == 0) continue;
            if (line[1][i] > line[1][j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int sol = 0;
    for (int i = 0; i <= count; i++) sol = max(sol, dp[i]);
    cout << n - sol << "\n";  
    
}