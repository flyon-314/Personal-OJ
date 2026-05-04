#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;
int color_paper[129][129];
int white_cnt = 0;
int black_cnt = 0;
void cutting(int r1, int r2, int c1, int c2)
{    int start = color_paper[r1][c1];

    if (r1 == r2 && c2 == c2) {
        start == 1 ? black_cnt++ : white_cnt++;
        return;
    }
    for (int i = r1; i < r2; i++) {
        for (int j = c1; j < c2; j++) {
            if (color_paper[i][j] != start) {
                int mid_r = (r1 + r2) / 2;
                int mid_c = (c1 + c2) / 2;

                cutting(r1, mid_r, c1, mid_c);     
                cutting(r1, mid_r, mid_c, c2);     
                cutting(mid_r, r2, c1, mid_c);     
                cutting(mid_r, r2, mid_c, c2);    
                return;
            }
        }
    }
    start == 1 ? black_cnt++ : white_cnt++;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> color_paper[i][j];
    }
    cutting(0, n, 0, n);
    cout << white_cnt << "\n" << black_cnt;
    
}