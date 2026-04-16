#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int dp[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = 1;
    dp[2] = 2;
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

    cout << dp[n] ;
    return 0;
}
