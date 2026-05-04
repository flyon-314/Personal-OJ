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

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int st = 0 , en = 0;
    
    while (st < n && en < n) {
        if (v[en] - v[st] < m) en++;
        else if (v[en] - v[st] >= m) {
            sol = min(sol, v[en] - v[st]);
            st++;
        }
    }
    cout << sol;
    return 0;
}