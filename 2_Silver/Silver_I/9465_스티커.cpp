#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int sticker [2][100001];
int dp[2][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while (t--) {
        int n;
        cin>>n;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) cin >> sticker[i][j];
        }
        dp[0][1] = sticker[0][1]; dp[1][1] = sticker[1][1];
        for (int i = 2; i <= n; i++) {
            dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }
        
        cout << max(dp[0][n], dp[1][n]) << "\n";
        
        for (int i = 0 ; i < 2 ; i++)  fill(dp[i], dp[i] + 100001, 0);
    }

    return 0;
}