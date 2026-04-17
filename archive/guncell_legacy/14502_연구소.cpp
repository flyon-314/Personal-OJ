#include <algorithm>
    #include <iosfwd>
    #include <iostream>
#include <queue>
#include <stdio.h>
    #include <string>
    #include <stack>
    #include <vector>
using namespace std;

int dx[4] = {1, 0 , -1 ,0};
int dy[4] = {0, -1, 0, 1};
int world[8][8];
void back_tracking(vector<vector<int>> &cell, vector<int> &temp, int t , int n)
{
    if (temp.size() == 3)
    {
        cell.push_back(temp);
        return; 
    }

    for (int i = t ; i < n; i++)
    {
        temp.push_back(i);
        back_tracking(cell, temp, i + 1, n);
        temp.pop_back();
    }

    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    vector <pair<int,int>> virus;
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int inp;
            cin >> inp ;
            world[i][j] = inp;
            if (inp == 2) virus.push_back(make_pair(i,j));
        }
    }
    
    vector<vector<int>> cell;
    vector<int> temp;
    back_tracking(cell, temp, 0 , n * m );

    int sol = 0;

    for (int i = 0; i < cell.size(); i++)
    {
        
        bool visited[8][8] = {false};
        vector<vector<int>> test;
        for (int j = 0; j < n; j++)
        {
            vector<int> tmp;
            for (int k = 0; k < m; k++)
            {
                tmp.push_back(world[j][k]);
            }
            test.push_back(tmp);
        }
        if (test[cell[i][0] / m][cell[i][0] % m] != 0 )continue;
        if (test[cell[i][1] / m][cell[i][1] % m] != 0) continue;
        if (test[cell[i][2] / m][cell[i][2] % m] != 0) continue;
        
        
        test[cell[i][0] / m][cell[i][0] % m] = 1;
        test[cell[i][1] / m][cell[i][1] % m] = 1;
        test[cell[i][2] / m][cell[i][2] % m] = 1;

        queue <pair<int, int>> q;
        for (int j = 0; j < virus.size(); j++)
        {
            q.push(virus[j]);
            visited[virus[j].first][virus[j].second] = true;
        }

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nexty = p.first + dy[dir];
                int nextx = p.second + dx[dir];

                if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
                if (visited[nexty][nextx] || test[nexty][nextx] == 1) continue;

                test[nexty][nextx] = 2;
                visited[nexty][nextx] = true;
                q.push(make_pair(nexty, nextx));
            }
        }

        int count = 0;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (test[x][y] == 0) count ++;
            }
        }

        sol = max(sol, count);
    }

    cout << sol << "\n";
}
