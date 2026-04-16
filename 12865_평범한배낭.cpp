#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int dp[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    int w, v;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        for (int j = k ; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);            
        }
    }
    cout << dp[k];
    return 0;
}