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

int mincraft[501][501];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, b;
    int max_height = 0;
    int anw = INT_MAX;
    int anw_height = 0;
    cin >> n >> m >> b;
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mincraft[i][j];
            max_height = max(max_height, mincraft[i][j]);
        }
    }

    for (int i = 0 ; i <= max_height ; i++) {
        int sum = 0, up = 0, down = 0;
        
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int diff = mincraft[j][k] - i;
                if (diff > 0) down += diff;
                else up += abs(diff);
            }
        }
        
        if (up > down + b) continue;
        else {
            sum = up + down * 2;
            if (sum <= anw) {
                anw = sum;
                anw_height = i;
            }
        }
    }
   cout << anw << " " << anw_height ;
    
    return 0;
}