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

int city[101][101];
int nxt[101][101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 101; i++) fill(city[i], city[i] + 101, INT_MAX);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = min(city[a][b], c);
        nxt[a][b] = b;
    }
    for (int i = 1 ; i <= n ; i++)city[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1 ; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (city[i][k] == INT_MAX || city[k][j] == INT_MAX) continue;
                if (city[i][j] > city[i][k] + city[k][j]){
                    city[i][j] = city[i][k] + city[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == INT_MAX) cout << "0" << " ";
            else cout << city[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == INT_MAX || city[i][j] == 0) cout << "0\n";
            else{
                vector <int> v;
                
                v.push_back(i);
                int next = nxt[i][j];
                while (next != j) {
                    v.push_back(next);
                    next = nxt[next][j];
                }
                v.push_back(j);

                cout << v.size() << " ";
                for (int k : v) cout << k << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}   