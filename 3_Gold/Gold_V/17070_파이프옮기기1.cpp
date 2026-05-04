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

int dx[3] = {1, 0, 1};
int dy[3] = {0, 1, 1};
int house[17][17];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> house[i][j];
    }
    
    int cnt = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 1}});

    while (!q.empty()) {
        pair<int,pair<int, int>> p = q.front();
        q.pop();
        if (p.second.first == n - 1 && p.second.second == n - 1) cnt++;
        
        else {
            for (int i = 0; i < 3; i++) {
                if (i != 2 && p.first != 2 && i != p.first ) continue;
                int nx = p.second.second + dx[i];
                int ny = p.second.first + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (house[ny][nx] == 1) continue;
                if (i == 2 && (house[ny - 1][nx] == 1 || house[ny][nx - 1] == 1)) continue;
                q.push({i, {ny, nx}});
            }
        }
    }
    cout << cnt;
    return 0;
    
}