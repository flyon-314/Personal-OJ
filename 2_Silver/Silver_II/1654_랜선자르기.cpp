#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

long line[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    long n_max = 0;
    cin >> n >> k;
    for (int i = 0 ;i < n; i++) {
        cin >> line[i];
        n_max = max(n_max, line[i]);
    }

    long left = 1, right = n_max;
    long sol = 0;
    
    while (left <= right) {
        long mid = (left + right) / 2;
        long l = 0;
        
        for (int i = 0 ; i < n ; i++) l += line[i] / mid;

        if (l >= k) {
            sol = max(sol, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << sol;
    return 0;
}
