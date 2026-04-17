#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void puyo_sort(vector<string> &s)
{
    for (int i = 0 ;  i < 6 ; i++)
    {
        int top = 11;
        for (int j = 11; j >= 0  ; j--)
        {
            if (s[j][i] != '.')
            {
                if (j == top) top--;
                else
                {
                    s[top][i] = s[j][i];
                    s[j][i] = '.';
                    top--;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> puyo;

    for (int i = 0 ;i  < 12 ; i++)
    {
        string str;
        cin >> str;
        puyo.push_back(str);
    }
    
    bool visited[12][6] = {false};
    queue<pair<int,int>> q;

    int sol = 0;
    bool chain = true;
    while (chain)
    {
        queue<pair<int,int>> py;
        chain = false;
        
        for (int i = 11 ; i >= 0 ; i--)
        {
            for (int j = 5 ; j >= 0 ; j--)
            {
                if (visited[i][j]) continue;
                visited[i][j] = true;
                if (puyo[i][j] == '.') continue;
                q.push(make_pair(i,j));
                int score = 1;
                
                while (!q.empty())
                {
                    pair<int,int> p = q.front();
                    q.pop();
                    py.push(p);
                    
                    for (int dir = 0 ; dir < 4 ; dir++)
                    {
                        int nextx = p.second + dx[dir];
                        int nexty = p.first + dy[dir];
                        if (nextx < 0 || nextx > 5 || nexty < 0 || nexty > 11) continue;
                        if (visited[nexty][nextx] || (puyo[p.first][p.second] != puyo[nexty][nextx])) continue;
                        if (puyo[i][j] == '.') continue;
                        
                        score++;
                        visited[nexty][nextx] = true;
                        q.push(make_pair(nexty,nextx));
                        py.push(make_pair(nexty,nextx));
                    }    
                }
                
               if (score > 3)
                {
                    chain = true;
                    while (!py.empty())
                    {
                        puyo[py.front().first][py.front().second] = '.';
                        py.pop();
                    }
                }
                else
                {
                    while (!py.empty())
                    {
                        py.pop();
                    }
                }
                
            }
            
        }
        
        if (chain)
        {
            sol++;
            for (int v = 0 ; v < 12 ; v++) fill(visited[v], visited[v]+6, false);
            puyo_sort(puyo);
            
        }
        
    } 
    cout << sol << "\n";
    return 0;
}
    