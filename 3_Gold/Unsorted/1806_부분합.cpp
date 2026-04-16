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

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int sol = INT_MAX;
    cin >> n >> m;

    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) v[i] += v[i - 1];
    
    int st = 0 , en = 0;
    
    while (st <= n && en <= n) {
        if (v[en] - v[st] < m) en++;
        else {
            sol = min(sol, en - st);
            st++;
        }
    }
    if (sol == INT_MAX) cout << 0;
    else cout << sol;
    return 0;
}