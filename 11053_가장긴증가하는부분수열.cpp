#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int num[1001];
int dp[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];

    fill(dp, dp + n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0 ; j--) {
            if (num[j] < num[i])dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    sort(dp, dp + n);
    cout << dp[n - 1] ;
    return 0;
}
