#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
const int MAX = 999999;
int rgb[3][1001];
int dp[3][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];
    for (int i = 1; i <= n; i++) {
        dp[0][i] = rgb[0][i] + min(dp[1][i - 1], dp[2][i - 1]);
        dp[1][i] = rgb[1][i] + min(dp[2][i - 1], dp[0][i - 1]);
        dp[2][i] = rgb[2][i] + min(dp[0][i - 1], dp[1][i - 1]);
    }
    cout << min(dp[0][n], min(dp[1][n], dp[2][n]));
    
    return 0;
}
