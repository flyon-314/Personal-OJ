#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

vector <int> node[100001];
int parent[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    queue <int> q;
    q.push(1);
    parent[1] = 1;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        
        for (int next : node[p]) {
            if (parent[next] == 0) {
                parent[next] = p;
                q.push(next);
            }
        }
    }
    for (int i = 2 ; i <= n; i++) cout << parent[i] << "\n";
    return 0;
}
