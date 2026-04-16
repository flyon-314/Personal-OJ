#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
constexpr int MAX = 9999999;
using namespace std;

int computer[101][101];
bool inpection[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, v;
    cin >> n >> v;

    for (int i = 0 ; i < v ; i++) {
        int x, y;
        cin >> x >> y;
        computer[x][y] = 1;
        computer[y][x] = 1;
    }

    queue <int> q;
    q.push(1);
    inpection[1] = true;
    int count = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i <= n; i++) {
            if (computer[x][i]) {
                if (inpection[i]) continue;
                inpection[i] = true;
                q.push(i);
                count++;
                computer[x][i] = 0;
                computer[i][x] = 0;
            }
        }
    }

    cout << count << "\n";
    return 0;
}
