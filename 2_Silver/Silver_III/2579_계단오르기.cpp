#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
#include <unordered_map>
constexpr int MAX = 9999999;
using namespace std;

int stair[301];
int dp[301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> stair[i];

    dp[1] = stair[1];
    dp[2] = stair[2] + stair[1];

    for (int i = 3; i <= n; i++) dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];
    cout << dp[n];

    return 0;
}
