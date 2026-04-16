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
vector<int> v;
void n_m( int n, int m, int cnt)
{
    if (cnt == m) {
        for (int i = 0 ; i < v.size() ; i++) cout << v[i] << ' ';
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(num[i]);
        n_m(n, m, cnt + 1);
        v.pop_back();
        visited[i] = false;
    }
}
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) cin >> num[i];
    sort (num + 1, num + n + 1 );
    n_m(n, m, 0);
    return 0;
}
