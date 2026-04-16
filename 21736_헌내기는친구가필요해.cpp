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

char campus[601][601];
bool visited[601][601];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    queue <pair <int, int> > q;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0 ; j < s.length(); j++) {
            campus[i][j] = s[j];
            if (s[j] == 'I') {
                q.push({i, j});
                visited[i][j] = true;
            }
        }    
    }

    int anw = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (campus[p.first][p.second] == 'P') anw++;
        for (int k = 0; k < 4; k++) {
            int nx = p.second + dx[k];
            int ny = p.first + dy[k];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (campus[ny][nx] == 'X' || visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    if (anw == 0) cout << "TT" << endl;
    else cout << anw ;
    return 0;
}   