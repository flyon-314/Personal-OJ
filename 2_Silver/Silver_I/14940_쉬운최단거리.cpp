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

int world[1001][1001];
int anw[1001][1001];
bool visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    pair<int, int> target;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] == 2) target = {i, j}; 
        }
    }

    queue <pair<int, int>> q;
    visited[target.first][target.second] = true;
    q.push(target);

    int cnt = 1;
    while (!q.empty()) {
        int s = q.size();
        
        while (s--) {
            pair<int, int> p = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int ny = p.first + dy[k];
                int nx = p.second + dx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx] || world[ny][nx] == 0) continue;

                visited[ny][nx] = true;
                anw [ny][nx] = cnt;
                q.push({ny, nx});
            }
        }
        cnt++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && world[i][j] == 1) cout << -1 << " ";
            else cout << anw[i][j] <<" ";
        }
        cout << "\n";
    }
}   