#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int wall[1001][1001];
bool visited[2][1001][1001];
int dy[4] = {0,0,1,-1};
int dx[4]={1,-1,0,0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) wall[i][j] = s[j] - '0';
    }

    queue <pair<int, pair<int, int>>> q;
    q.push({0,{0, 0}});
    visited[0][0][0] = true;
    int cnt = 1;
    
    while (!q.empty()) {
        int s = q.size();

        while (s--) {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            if (p.second.first == n - 1 && p.second.second == m - 1) {
                cout << cnt;
                return 0;
            }
            for (int dir = 0; dir < 4; dir++) {
                int ny = p.second.first + dy[dir];
                int nx = p.second.second + dx[dir];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (wall[ny][nx] == 0 && visited[p.first][ny][nx] == false) {
                    q.push({p.first,{ny, nx}});
                    visited[p.first][ny][nx] = true;
                }
                else if (wall[ny][nx] == 1 && p.first == 0 && visited[p.first + 1][ny][nx] == false) {
                    q.push({p.first + 1,{ny, nx}});
                    visited[p.first + 1][ny][nx] = true;
                }
                else continue;
            }
        }
        cnt++;
    }
    cout << -1;
    
    return 0;
}