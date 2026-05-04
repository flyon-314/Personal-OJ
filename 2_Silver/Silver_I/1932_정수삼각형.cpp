#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int tri [501][501];
int dp [501][501];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cin >> tri[i][j];
    }
    int sol = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) sol = max(sol ,dp[i][j] = tri[i][j] + max(dp[i-1][j - 1], dp[i - 1][j]));
    }

    cout << sol;
    return 0;
}
