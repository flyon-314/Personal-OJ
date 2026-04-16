#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

// int dx[4] = {1, 0, -1 , 0};
// int dy[4] = {0, -1, 0, 1};
// int dot[1001];
int map[1001][1001];
bool visited[1001];

void dfs(int x)
{
    if (visited[x]) return ;
    visited[x] = true;
    cout << x << " ";
    for (int y = 0; y < 1001; y++) {
        if (!map[x][y] || visited[y]) continue;
        dfs(y);
    }

    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;

    cin >> n >> m >> s;
    for (int i = 0 ; i < m ; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    dfs(s);
    cout << "\n";

    fill(visited, visited+1001, false);

    queue <int> q;
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        
        for (int y = 1; y <= n; y++) {
            if (!map[x][y] || visited[y]) continue;
            visited[y] = true;
            q.push(y);
        }
    }
    
    
    return 0;
}
