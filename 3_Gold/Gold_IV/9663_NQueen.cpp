#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

bool chess[16];
bool line1[31];
bool line2[31];
int sol;
void n_queen(int r, int s)
{
    if (r > s) {
        sol++;
        return;
    }
    for (int i = 1; i <= s; i++) {
        if (line1[r + i] || line2[s + r - i] || chess[i]) continue;
        line1[r + i] = line2[s + r - i] = chess[i] = true;
        n_queen(r + 1, s);
        line1[r + i] = line2[s + r - i] = chess[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    n_queen(1, n);
    cout << sol;
    return 0;
}