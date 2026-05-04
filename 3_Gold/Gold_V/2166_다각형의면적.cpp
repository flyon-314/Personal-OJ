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
long double polygon[10001][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long double xy = 0,yx = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> polygon[i][0] >> polygon[i][1];
    polygon[n][0] = polygon[0][0]; polygon[n][1] = polygon[0][1];
    for (int i = 1; i <= n; i++) {
        xy += polygon[i - 1][1] * polygon[i][0];
        yx += polygon[i - 1][0] * polygon[i][1];
    }
    cout << fixed << setprecision(1) << abs(xy - yx) / 2;
    return 0;
}