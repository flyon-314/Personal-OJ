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

int sudoku[9][9];
bool ifCheck(int r, int c, int num)
{
    for (int i = 0; i < 9; i++) {
        if (sudoku[r][i] == num || sudoku[i][c] == num) return false;
    }
    int boxRow = (r / 3) * 3;
    int boxCol = (c / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[boxRow + i][boxCol + j] == num) return false;
        }
    }
    return true;
}
bool solve(int seq)
{
    if (seq == 81) return true;
    int r = seq / 9;
    int c = seq % 9;
    if (sudoku[r][c] != 0 ) return solve(seq + 1);

    for (int i = 1; i <= 9; i++) {
        if (ifCheck(r, c, i)) {
            sudoku[r][c] = i;
            if (solve(seq + 1)) return true;
            sudoku[r][c] = 0;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            sudoku[i][j] = s[j] - '0';
        }
    }
    solve(0);
    for (int i = 0 ;
        i < 9; i++) {
        for (int j = 0 ; j < 9; j++) {
            cout << sudoku[i][j];
        }
        cout <<"\n";
    }
}   