#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
bool visited[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    queue <int> q;
    q.push(n);

    int cnt = 0;
    int time = 0;
    while(!q.empty()) {
        int s = q.size();

        while (s--) {
            int p = q.front();
            q.pop();
            visited[p] = true; 
            
            if (p == k) cnt++;

            int next_pos[3] = {p - 1, p + 1, p * 2};
            for (int next : next_pos) {
                if (next >= 0 && next <= 100000 && !visited[next]) {
                    q.push(next);
                }
            }
        }
        if (cnt != 0) break; 
        time++;
    }
    cout << time << "\n" << cnt;
    return 0;
}