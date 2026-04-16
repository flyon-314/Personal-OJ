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

bool compair(pair<int,string> x, pair<int,string> y)
{
    return x.first < y.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector <pair<int, string>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;
        v.push_back({x, s});
    }
    stable_sort(v.begin(), v.end(), compair);

    for (pair<int, string> x : v) cout << x.first << " " << x.second << "\n";

    
    return 0;
}