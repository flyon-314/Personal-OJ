#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

int dice[6] = {1 ,2 ,3 ,4 ,5 ,6};
int visited[11][11] ={0};
int main(   )
{
    int map[11][11] = {0};
    int N ,M;
    cin >> N >> M;

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            map[i][j] = (i -1) * 10 + j;
        }
    }
    
    for (int i = 0; i < N + M; i++)
    {
        int x ,y;
        cin >> x >> y;

        map[(x-1)/10 +1][(x-1)%10 +1] = y;
    }

    int sol = 0;

    queue <int> q;
    q.push(1);
    visited[1][1] = 1;

    while (!q.empty())
    {
        int size = q.size();

        
        for (int i = 0; i < size; i++)
        {
            
            int temp = q.front();
            if (temp == 100)
            {
                cout << sol << "\n";
                return 0;
            }
            q.pop();

            for (int dir = 0; dir < 6; dir++)
            {
                int nextX = temp + dice[dir];
                int nextY = map[(nextX-1)/10 +1][(nextX-1)%10 +1];
                if (nextX > 100) continue;
                if (visited[(nextX-1)/10 +1][(nextX-1)%10 +1] == 1) continue;

                if (nextX != nextY)
                {
                    visited[(nextX-1)/10 +1][(nextX-1)%10 +1] = 1;
                    visited[(nextY-1)/10 +1][(nextY-1)%10 +1] = 1;
                    q.push(nextY);
                    
                }
                else
                {
                    visited[(nextX-1)/10 +1][(nextX-1)%10 +1] = 1;;
                    q.push(nextX);
                }
                
            }
        }
        sol++;
    }
}
