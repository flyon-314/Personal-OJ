#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int tree[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> tree[i];

    int left = 0 , right = 1000000000;
    int sol = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long sum = 0;
        
        for (int i = 0 ; i < n ; i++) {
            if (tree[i] - mid >= 0) sum += tree[i] - mid;
        }
        if (sum < m) {
            right = mid - 1;
        }
        else {
            sol = max(sol, mid);
            left = mid + 1;
        }
    }
    cout << sol;
}