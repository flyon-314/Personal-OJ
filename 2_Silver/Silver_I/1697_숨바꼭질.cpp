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
#include <unordered_set>

using namespace std;

bool visited[120001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    queue <int> q;
    q.push(n);
    visited[n] = true;
    
    int sol = 0;
    while (!q.empty()) {
        int s = q.size();

        while (s--) {
            int cur = q.front();
            q.pop();

            if (cur == m) {
                cout << sol ;
                return 0;
            }
        
            if (cur - 1 >= 0 && !visited[cur - 1]) {
                q.push(cur - 1);
                visited[cur - 1] = true;
            }
            if (cur + 1 < 120000 && !visited[cur + 1] ) {
                q.push(cur + 1);
                visited[cur + 1] = true;
            }
            if (cur * 2 < 120000 && !visited[cur * 2]) {
                q.push(cur * 2);
                visited[cur * 2] = true;
            }
        }
        sol++;
    }
    
    return 0;
}   