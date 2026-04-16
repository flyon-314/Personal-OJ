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
int num[2001];
int dp[2001][2001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        dp[i][i] = 1;
    }

    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j + i<= n; j++){
            if (num[j] == num[j + i]) {
                if (i == 1) dp[j][j + i] = 1;
                else if ( dp[j + 1][j + i -1] == 1)dp[j][j + i] = 1;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}