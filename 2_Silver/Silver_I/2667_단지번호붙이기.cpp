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
int housing[26][26];
bool visited[26][26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            housing[i][j] = (s[j] - '0');
        }
    }
    
    vector <int> sol;
    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n; j++) {
            if (housing[i][j] == 0 || visited[i][j]) continue;
            
            queue <pair<int, int>> q;
            visited[i][j] = true;
            
            q.push({i, j});

            int cnt = 0;
    
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int ny = p.first + dy[k];
                    int nx = p.second + dx[k];

                    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    if (visited[ny][nx] || housing[ny][nx] == 0) continue;

                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
                cnt++;
            }

            sol.push_back(cnt);
        }
    }
    sort(sol.begin(), sol.end());

    cout << sol.size() << "\n";
    for (int s : sol) cout << s << "\n";
}   