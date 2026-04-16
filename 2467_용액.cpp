#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int liquid[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, min_num = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> liquid[i];

    pair <int, int> anw = {1000000001,1000000001};
    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        int target = -liquid[i];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid != i) {
                if (abs (anw.first + anw.second) > abs(liquid[i] + liquid[mid])) anw = {liquid[mid], liquid[i]};
            }
            if (target < liquid[mid]) right = mid - 1;
            else left = mid + 1;
        }
    }
    if (anw.first > anw.second) swap(anw.first, anw.second);
    cout << anw.first << " " << anw.second;
    return 0;
}