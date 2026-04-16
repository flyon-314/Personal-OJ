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
#include <stack>
#include <unordered_set>

using namespace std;

char board[51][51];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) board[i][j] = s[j];
    }

    int anw = 80;
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            for (int wb = 0; wb < 2; wb++) {
                bool white = wb ? false : true;
                int cnt = 0;
                for (int y = i ; y < i + 8 ; y++) {
                    white = !white;
                    for (int x = j ; x < j + 8 ; x++) {
                        if (board[y][x] == 'W' && !white) cnt++;
                        else if (board[y][x] == 'B' && white) cnt++;
                        white = !white;
                    }
                }

                anw = min(anw, cnt);
            }
            
        }
    }

    cout << anw;
}   