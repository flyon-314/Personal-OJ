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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int world[1001][1001];
int new_world[1001][1001];
bool visited[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); ++j) {
            world[i][j] = (s[j] - '0');
        }
    }

    queue <pair<int,int>> q;
    vector <int> area;
    int idx = 2;
    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (world[i][j] == 1 || visited[i][j]) continue;
            int cnt = 0;
            new_world[i][j] = idx;
            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                pair<int,int> p = q.front();
                q.pop();
                cnt++;
                for (int dir = 0; dir < 4; dir++) {
                    int ny = p.first + dy[dir];
                    int nx = p.second + dx[dir];

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if (world[ny][nx] == 1 || visited[ny][nx]) continue;

                    visited[ny][nx] = true;
                    new_world[ny][nx] = idx;
                    q.push({ny, nx});
                }
            }
            area.push_back(cnt);
            idx++;
        }
    }

    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < m ; j++) {
            
            if (world[i][j] == 0) {
                cout << 0;
            }
            else if (world[i][j] == 1) {
                int sum = 1;
                set <int> st;
                
                for (int dir = 0; dir < 4; dir++) {
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if (world[ny][nx] == 1 || new_world[ny][nx] == 0) continue;

                    st.insert(new_world[ny][nx]);
                }

                for (int s : st) {
                    sum += area[s - 2];
                }
                
                cout << sum % 10;
            }
        }
        cout << "\n";
    }
    
    return 0;
    
}   