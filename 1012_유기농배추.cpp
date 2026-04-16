#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, -1, 0, 1};
int baechu[51][51];
bool visited[51][51];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            baechu[x][y] = 1;
        }

        int ans = 0;
        queue <pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (baechu[i][j] && !visited[i][j]) {
                    ans++;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        
                        for (int dir = 0 ; dir < 4; dir++) {
                            int nx = p.first + dx[dir];    
                            int ny = p.second + dy[dir];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (!baechu[nx][ny] || visited[nx][ny]) continue;
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }

        cout << ans << "\n";
        for (int i = 0; i <= m; i++) {
            fill (baechu[i], baechu[i] + 51, 0);
            fill (visited[i], visited[i] + 51, 0);
        }
    }
    
    return 0;
}
