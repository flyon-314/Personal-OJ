#include <iostream>
#include <vector>

using namespace std;

int m, n;
int world[501][501];
int dp[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int dfs(int y, int x) {
    if (y == m-1 && x == n-1) return 1;
    if (dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;
    
    for (int dir = 0 ; dir < 4 ; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (world[ny][nx] >= world[y][x]) continue;

        dp[y][x] += dfs(ny, nx);
    }

    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < m; i++) fill(dp[i], dp[i] + n, -1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) cin >> world[i][j];
    }

    cout << dfs(0, 0) << "\n";
}