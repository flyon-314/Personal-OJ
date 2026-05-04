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

int num[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        if (lis.empty() || lis.back() < num[i]) {
            lis.push_back(num[i]);
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), num[i]);
            *it = num[i];
        }
    }
    cout << lis.size() << "\n";
    return 0;
    
}   