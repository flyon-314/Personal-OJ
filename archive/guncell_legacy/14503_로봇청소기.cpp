#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int state[4] = {0, 1, 2, 3}; // 북, 동, 남, 서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int room[51][51];
int r_state;
bool visited[51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r, c;
    cin >> n >> m ;
    cin >> r >> c >> r_state;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> room[i][j];

    
    bool flag = true;
    int answer = 0;

    while (flag)
    {
        if (room[r][c] == 0)
        {
            room[r][c] = 2;
            answer++;
        }

        flag = false;
        
        for (int i = 0 ; i < 4; i++)
        {
            r_state = (r_state + 3) % 4;

            int nextx = c + dx[r_state];
            int nexty = r + dy[r_state];

            if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) continue;
            if (room[nexty][nextx] != 0) continue;
            
            flag = true;
            
            r = nexty;
            c = nextx;
            break;
        }
        
        if (!flag)
        {
            r += dy[(r_state + 2) % 4];
            c += dx[(r_state + 2) % 4];
            flag = true;
            if (c < 0 || r < 0 || c >= m || r >= n || room[r][c] == 1) flag = false;
        }
    }

     cout << answer << "\n";
        
}
        