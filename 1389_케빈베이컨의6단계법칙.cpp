#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <climits>
#include <unordered_set>

using namespace std;

int friends[101][101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 101; i++) fill (friends[i], friends[i] + 101, INT_MAX);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a][b] = 1;
        friends[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; ++k) {
                if (friends[j][i] == INT_MAX || friends[i][k] == INT_MAX) continue;
                friends[j][k] = min(friends[j][k], friends[j][i] + friends[i][k]);
            }
        }
    }
    
    int cnt = INT_MAX;
    int anw;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            sum += friends[i][j];
        }
        if (sum < cnt) {
            anw = i;
            cnt = sum;
        }
    }
    
    cout << anw;
    return 0;
    
}   