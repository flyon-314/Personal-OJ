#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
string s[10000];
int visited[10000] = {0};

int main(   )
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    while (T--)
    {
        fill(visited, visited + 10000, 0);
        fill(s, s + 10000, "");
        int a,b;
        
        cin >> a >> b;

        visited[a] = 1;
        queue <int> q;
        q.push(a);
        
        while (!q.empty())
        {
            int temp = q.front();
            if (temp == b) break;
            int n;
            q.pop();
        
            for (int dir = 0 ; dir < 4; dir++)
            {
                int num = 0;
                int d1,d2,d3,d4;
                switch (dir)
                {
                case 0:
                    num = temp * 2;
                    if (num >= 10000) num %= 10000;
                    if (visited[num] == 1 ) continue;
                    else visited[num] = 1;
                    s[num] = s[temp] + 'D';
                    q.push(num);
                    continue;
                case 1:
                    num = temp - 1;
                    if (num <0) num = 9999;
                    if (visited[num] == 1 ) continue;
                    else visited[num] = 1;
                    s[num] = s[temp] + 'S';
                    q.push(num);
                    continue;
                case 2:
                    n = temp;
                    d1 = n / 1000 ;
                    n %= 1000;
                    d2 = n / 100;
                    n %= 100;
                    d3 = n / 10;
                    d4 = n % 10;

                    num = d2 * 1000 + d3 * 100 + d4 * 10 + d1;
                    if (visited[num] == 1) continue;
                    else visited[num] = 1;
                    s[num] = s[temp] + 'L';
                    q.push(num);
                    continue;
                case 3  :
                    n = temp;
                    d1 = n / 1000 ;
                    n %= 1000;
                    d2 = n / 100;
                    n %= 100;
                    d3 = n / 10;
                    d4 = n % 10;

                    num = d4 * 1000 + d1 * 100 + d2 * 10 + d3;
                    if (visited[num] == 1) continue;
                    else visited[num] = 1;
                    s[num] = s[temp] + 'R';
                    q.push(num);
                    continue;
             
                }
            }
        }
        cout << s[b] << "\n";
        
    }
}
