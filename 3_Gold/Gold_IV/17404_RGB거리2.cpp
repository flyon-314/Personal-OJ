#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;
const int n_max = 99999999;

int rgb[3][1001];
int dp[3][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sol = n_max;
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> rgb[0][i] >> rgb[1][i] >> rgb[2][i];

    dp[0][1] = n_max;
    dp[1][1] = rgb[1][1] + rgb[0][0];
    dp[2][1] = rgb[2][1] + rgb[0][0];

    for (int i = 2; i < n; i++) {
        if (i == n - 1) {
            dp[0][i] = n_max;
            dp[1][i] = min(dp[2][i - 1], dp[0][i - 1]) + rgb[1][i];
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + rgb[2][i];
        }
        else {
            dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + rgb[0][i];
            dp[1][i] = min(dp[2][i - 1], dp[0][i - 1]) + rgb[1][i];
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + rgb[2][i];    
        }
        
    }

    for (int i = 0; i < 3; i++) sol = min(sol, dp[i][n - 1]);
    for (int i = 0 ; i < 3; i++) fill(dp[i], dp[i] + n, 0);

    dp[0][1] = rgb[0][1] + rgb[1][0];
    dp[1][1] = n_max;
    dp[2][1] = rgb[2][1] + rgb[1][0];

    for (int i = 2; i < n; i++) {
        if (i == n - 1) {
            dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + rgb[0][i];
            dp[1][i] = n_max;
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + rgb[2][i];
        }
        else {
            dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + rgb[0][i];
            dp[1][i] = min(dp[2][i - 1], dp[0][i - 1]) + rgb[1][i];
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + rgb[2][i];  
        }
        
    }

    for (int i = 0; i < 3; i++) sol = min(sol, dp[i][n - 1]);
    for (int i = 0 ; i < 3; i++) fill(dp[i], dp[i] + n, 0);

    dp[0][1] = rgb[0][1] + rgb[2][0];
    dp[1][1] = rgb[1][1] + rgb[2][0];
    dp[2][1] = n_max;

    for (int i = 2; i < n; i++) {
        if (i == n - 1) {
            dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + rgb[0][i];
            dp[1][i] = min(dp[2][i - 1], dp[0][i - 1]) + rgb[1][i];
            dp[2][i] = n_max;
        }
        else {
            dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + rgb[0][i];
            dp[1][i] = min(dp[2][i - 1], dp[0][i - 1]) + rgb[1][i];
            dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + rgb[2][i];  
        }
    }

    for (int i = 0; i < 3; i++) sol = min(sol, dp[i][n - 1]);

    cout << sol;
    return 0;
}