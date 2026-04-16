#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int dp[1200];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, n;
    cin >> c >> n;

    fill (dp, dp + 1200, 99999999);
    vector <pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int cost, profit;
        cin >> cost >> profit;
        v.push_back(make_pair(cost, profit));
    }
    
    dp[0] = 0;
    for (int i = 1 ; i <= c + 100; i++) {
        for (pair<int,int> p : v) {
            if (i - p.second >= 0) {
                dp[i] = min(dp[i], dp[i - p.second] + p.first);
            }
        }
    }
    
    int sol = dp[c];
    for (int i = c ;i < c + 100 ; i++) sol = min(sol, dp[i]);
    cout << sol << "\n";
}