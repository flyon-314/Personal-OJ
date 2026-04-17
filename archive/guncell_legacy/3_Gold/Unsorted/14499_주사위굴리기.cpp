#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int world[21][21];
int dice[4][3];
int dx[4] = {1, -1 , 0, 0};
int dy[4] = {0, 0, -1, 1};

void roll_dice(int num)
{
    if (num == 1)
    {
        int tmp = dice [3][1];
        dice [3][1] = dice [1][2];
        dice [1][2] = dice [1][1];
        dice [1][1] = dice [1][0];
        dice [1][0] = tmp;
    }
    else if (num == 2)
    {
        int tmp = dice [1][0];
        dice [1][0] = dice [1][1];
        dice [1][1] = dice[1][2];
        dice [1][2] = dice [3][1];
        dice [3][1] = tmp;
    }
    else if (num == 3)
    {
        int tmp = dice [0][1];
        dice [0][1] = dice [1][1];
        dice [1][1] = dice [2][1];
        dice [2][1] = dice[3][1];
        dice[3][1] = tmp;
    }
    else if (num == 4)
    {
        int tmp = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = tmp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x, y ,k;
    cin >> n >> m >> y >> x >> k;

    for (int i = 0 ;i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> world[i][j];
        }
    }

    while (k--)
    {
        int t;
        cin >> t;

        int nexty = y + dy[t-1];
        int nextx = x + dx[t-1];

        if (nextx > m - 1 || nexty > n - 1 || nextx < 0 || nexty < 0) continue;

        roll_dice(t);

        if (world[nexty][nextx] == 0) world[nexty][nextx] = dice[3][1];
        else
        {  
            dice[3][1] = world[nexty][nextx];
            world[nexty][nextx] = 0;
        }

        x = nextx;
        y = nexty;
        
        cout << dice[1][1] << "\n";
    }
    
    
}
    