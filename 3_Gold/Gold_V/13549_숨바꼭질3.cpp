#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
bool visited[200001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    queue <pair<int,int>> q;
    q.push({n, 0});
    visited[n] = true;
    
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        if (p.first == k) {
            cout << p.second << "\n";
            return 0;
        }
        while (p.first * 2 <= 200001 && !visited[p.first * 2]) {
            visited[p.first * 2] = true;
            q.push({p.first * 2, p.second});
        }

        if (p.first - 1 >= 0 && !visited[p.first - 1]) {
            visited[p.first - 1] = true;
            q.push({p.first - 1, p.second + 1});
        }
        if (p.first + 1 <= k && !visited[p.first + 1]) {
            visited[p.first + 1] = true;
            q.push({p.first + 1, p.second + 1});
        }
        
    }
    return 0;
}