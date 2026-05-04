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
#include <stack>
#include <unordered_set>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int maze[101][101];
bool visited[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            maze[i][j] = (s[j] - '0');
        }
    }

    queue <pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});

    int anw = 1;
    
    while (!q.empty()) {
        int s = q.size();

        while (s--) {
            pair<int, int> p = q.front();
            q.pop();

            if (p.first == n - 1 && p.second == m - 1) {
                cout << anw;
                return 0;
            }
            for (int k = 0; k < 4; k++) {
                int ny = p.first + dy[k];
                int nx = p.second + dx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx] || maze[ny][nx] == 0) continue;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }

        anw++;
    }
    cout << anw;
    
}   