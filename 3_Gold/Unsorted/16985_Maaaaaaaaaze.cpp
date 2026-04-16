#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int maze[5][5][5];
int save[5][5][5];
bool visited[5][5][5];
bool m_visited[5];

int side [8][3] = {{0, 0, 0}, {4, 4, 4}, {0, 0, 4}, {4, 4, 0}, {0, 4, 4}, {4, 0, 0}, {0, 4, 0}, {4, 0, 4} };

void lotate(int panel)
{
    int temp[6][6] = {};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            temp[i][j] = maze[panel - 1][4 - j][i];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            maze[panel - 1][i][j] = temp[i][j];
        }
    }
}

void orign()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                maze[i][j][k] = save[i][j][k];
            }
        }
    }

    return;
}
void replace_maze(vector<int> &v)
{
    int world[6][6][6];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                world[v[i]][j][k] = maze[i][j][k];
                
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                maze[i][j][k] = world[i][j][k];
            }
        }
    }
}
void mix (vector<vector<int>> &v, vector<int> &q)
{
    if (q.size() == 5)
    {
        v.push_back(q);
        return;
    }
    for (int i = 0 ; i < 5; i++)
    {
        if (!m_visited[i])
        {
            q.push_back(i);
            m_visited[i] = true;
            mix(v, q);
            m_visited[i] = false;
            q.pop_back();
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> maze[i][j][k];
                save[i][j][k] = maze[i][j][k];
            }
        }
    }
    
    vector <vector<int>> number;
    vector <int> temp;
    mix(number, temp);
    
    int answer = 999999999;
    
    for (int i = 0; i < number.size(); i++)
    {
        orign();
        replace_maze(number[i]);
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    for (int m = 0; m < 4; m++)
                    {
                        for (int n = 0; n < 4; n++)
                        {
                            for (int o = 0; o < 4; o++)
                            {
                                pair<int,pair<int,int>> s;
                                pair<int,pair<int,int>> e;
                                
                                s.first = side[o * 2][0];
                                s.second.first = side[o * 2][1];
                                s.second.second = side[o * 2][2];
                                
                                e.first = side[o * 2 + 1][0];
                                e.second.first = side[o * 2 + 1][1];
                                e.second.second = side[o * 2 + 1][2];

                                if (maze[s.first][s.second.first][s.second.second] == 0) continue;
                                if (maze[e.first][e.second.first][e.second.second] == 0) continue;

                                queue<pair<int,pair<int,int>>> q;
                                q.push(s);
                                visited[s.first][s.second.first][s.second.second] = true;
                                
                                int sol = 0;
                                bool flag = false;
                                
                                while (!q.empty())
                                {
                                    int m_size = q.size();
                                    for (int maze_s = 0 ; maze_s < m_size ; maze_s++)
                                    {
                                        pair<int,pair<int,int>> p = q.front();
                                        q.pop();

                                        if (p.first == e.first && p.second.first == e.second.first && p.second.second == e.second.second)
                                        {
                                            flag = true;
                                            answer = min(answer, sol);
                                            break;
                                        }
                                        for (int dir = 0; dir < 6; dir++)
                                        {
                                            int nextx = p.first + dx[dir];
                                            int nexty = p.second.first + dy[dir];
                                            int nextz = p.second.second + dz[dir];
                                            
                                            if (nextx < 0 || nextx > 4 || nexty < 0 || nexty > 4 || nextz < 0 || nextz > 4) continue;
                                            if (visited[nextx][nexty][nextz] || maze[nextx][nexty][nextz] == 0) continue;

                                            visited[nextx][nexty][nextz] = true;
                                            q.push(make_pair(nextx, make_pair(nexty, nextz)));
                                        }
                                    }
                                    
                                    sol++;
                                    if (flag) break;
                                    
                                }

                                for (int v_r1 = 0 ;v_r1 < 5; v_r1++)
                                {
                                    for (int v_r2 = 0 ;v_r2 < 5; v_r2++)
                                        fill(visited[v_r1][v_r2], visited[v_r1][v_r2] + 5, false);
                                }
                            }
                        }
                        lotate(5);
                    }
                    lotate(4);
                }
                lotate(3);
            }
            lotate(2);
        }
        lotate(1);
    }
    if (answer != 999999999) cout << answer << "\n";
    else cout << -1 <<"\n";
   
}
        