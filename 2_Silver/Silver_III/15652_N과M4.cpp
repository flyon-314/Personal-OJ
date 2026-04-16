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
vector<int> v;
void n_m(int start, int n, int m, int cnt)
{
    if (cnt == m) {
        for (int i = 0 ; i < v.size() ; i++) cout << v[i] << ' ';
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; i++) {
        v.push_back(i);
        n_m(i, n, m, cnt + 1);
        v.pop_back();
    }
}
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    n_m(1, n, m, 0);
    return 0;
}
