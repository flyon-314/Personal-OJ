#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int dp[50001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i * i < 50001; i++) dp[i * i] = 1;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1) continue;
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j * j < i ; j++) dp[i] = min(dp[i - j * j] + 1,dp[i] );
    }
    cout << dp[n];
    
    return 0;
}
