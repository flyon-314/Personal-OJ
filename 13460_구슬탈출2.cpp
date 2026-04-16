#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
int ans = 11;
char world[11][11];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void move(char board[11][11], int& r, int& c, int dir) {
    while (true) {
        int nr = r + dx[dir];
        int nc = c + dy[dir];

        if (board[nr][nc] == '#' || board[nr][nc] == 'R' || board[nr][nc] == 'B') break;
        if (board[nr][nc] == 'O') {
            board[r][c] = '.';
            r = nr;
            c = nc;
            break;
        }

        board[nr][nc] = board[r][c];
        board[r][c] = '.';
        r = nr;
        c = nc;
    }
}

void solve(int count, char board[11][11]) {
    if (count > 10) return;

    if (count >= ans) return;

    char temp_board[11][11];
    int cur_rx, cur_ry, cur_bx, cur_by;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'R') {
                cur_rx = i;
                cur_ry = j;
            } else if (board[i][j] == 'B') {
                cur_bx = i;
                cur_by = j;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                temp_board[r][c] = board[r][c];
            }
        }
        
        int rx = cur_rx, ry = cur_ry;
        int bx = cur_bx, by = cur_by;
        
        bool red_first = false;
        if (i == 2 && rx < bx) red_first = true;
        if (i == 0 && rx > bx) red_first = true;
        if (i == 1 && ry < by) red_first = true;
        if (i == 3 && ry > by) red_first = true;
        
        if (red_first) {
            move(temp_board, rx, ry, i);
            move(temp_board, bx, by, i);
        }
        else {
            move(temp_board, bx, by, i);
            move(temp_board, rx, ry, i);
        }

        if (temp_board[bx][by] == 'O') continue;

        if (temp_board[rx][ry] == 'O') {
            ans = min(ans, count);
            continue;
        }

        bool check = false;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (board[r][c] != temp_board[r][c]) {
                    check = true;
                    break;
                }
            }
            if (check) break;
        }

        if (check) solve(count + 1, temp_board);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> world[i][j];
        }
    }

    solve(1, world);

    if (ans > 10) cout << -1 << "\n";
    else cout << ans << "\n";
    

    return 0;
}