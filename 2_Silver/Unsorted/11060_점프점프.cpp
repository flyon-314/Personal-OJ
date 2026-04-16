#include <bits/stdc++.h>

using namespace std;

vector<int> a;
int dp[1001];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int current_pos = q.front();
        q.pop();

        int jump_range = a[current_pos];

        for (int i = 1; i <= jump_range; i++) {
            int next_pos = current_pos + i;

            if (next_pos >= n) continue;

            if (dp[next_pos] == -1) {
                dp[next_pos] = dp[current_pos] + 1;
                q.push(next_pos);
            }
        }
    }

    cout << dp[n - 1];

    return 0;
}