#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int matrix[1025][1025];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1] + num;
        }
    }

    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << matrix[x2][y2] + matrix[x1 - 1][y1 - 1] - matrix[x2][y1 -1] - matrix[x1 - 1][y2] << "\n";
    }

    return 0;
}