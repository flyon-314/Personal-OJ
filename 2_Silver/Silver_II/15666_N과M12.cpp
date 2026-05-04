#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
bool visited[9];
int num[9];
vector<vector<int>> v;
void n_m( int n, int m, int cnt, vector<int> &num_v)
{
    if (cnt == m) {
        v.push_back(num_v);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (cnt  > 0 && num_v.back() >  num[i]) continue;
        num_v.push_back(num[i]);
        n_m(n, m, cnt + 1, num_v);
        num_v.pop_back();
    }
}
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cin >> num[i];
    vector <int> num_v;
    sort (num + 1, num + n + 1 );
    n_m(n, m, 0, num_v);
    
    for (auto it = v[0].begin(); it != v[0].end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size() ; i++) {
        if (v[i - 1] == v[i]) continue;
        for (auto it = v[i].begin(); it != v[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
