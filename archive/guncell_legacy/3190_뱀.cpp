#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <list>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int board[101][101];
int state[4] = {0, 1, 2, 3}; //동, 남, 서, 북
int head_state = 0;
int tail_state = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> head, tail;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k ;
    cin >> n;
    cin >> k;

    while (k--)
    {
        int i, j;
        cin >> i >> j;

        board[i - 1][j - 1] = 1;
    }

    int l;
    cin >> l;

    queue <pair<int, char> > head_q;
    queue <pair<int, pair<int,char>> > tail_q;

    while (l--)
    {
        int count;
        char st;
        cin >> count >> st;

        head_q.push(make_pair(count, st));
    }
    
    board[0][0] = 2;
    head = make_pair(0, 0);
    tail = make_pair(0, 0);
    int answer = 0;
    
    while (true)
    {
        int nexty = head.first +dy [head_state];
        int nextx = head.second +dx [head_state];
        
        answer++;
        // cout << endl << answer << endl ;
        // cout << "tail : (" << tail.first << ", " << tail.second << ")" << endl ;
        // cout << "head : (" << head.first << ", " << head.second << ")" << endl ;
        // for (int i  = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << board[i][j] <<" ";
        //     }
        //     cout << endl;
        // }
        //
        if (tail.first < 0 || tail.first >=n || tail.second < 0 || tail.second >=n) break;
        if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= n) break;
        if (board[nexty][nextx] > 1 && board[nexty][nextx] < 5) break;

        if (board[nexty][nextx] == 1) board[nexty][nextx] = 2;
        else
        {
            board[nexty][nextx] = 2;
            board[tail.first][tail.second] = 0;
            

            if (!tail_q.empty() && tail.first == tail_q.front().first && tail.second == tail_q.front().second.first)
            {
                if (tail_q.front().second.second == 'D')tail_state = (tail_state + 1) % 4;
                else tail_state = (tail_state + 3) % 4;

                tail_q.pop();
            }
            tail.first += dy[tail_state];
            tail.second += dx[tail_state];
        }


        if (!head_q.empty() && head_q.front().first == answer)
        {
            if (head_q.front().second == 'D'){
                tail_q.push(make_pair(nexty, make_pair(nextx, 'D')));
                head_state = (head_state + 1) % 4;
            }
            else
            {
                tail_q.push(make_pair(nexty, make_pair(nextx, 'L')));
                head_state = (head_state + 3) % 4;
            }

            head_q.pop();
        }
    
        head.first = nexty;
        head.second = nextx;
    }

    cout << answer << "\n";
}
        