#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i];
    }

    int max_count = 0;
    
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (boxes[j] < boxes[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dp[i] > max_count) {
            max_count = dp[i];
        }
    }

    cout << max_count << endl;

    return 0;
}