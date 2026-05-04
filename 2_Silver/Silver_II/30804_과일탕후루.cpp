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

int fruit[10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i];

    int st = 0, en = 0;
    int cnt = 0;
    int sol = 0;
    while ( en < n) {
        if (fruit[v[en]] == 0) cnt++;
        fruit[v[en++]]++;

        while (cnt > 2) {
            if (--fruit[v[st]] == 0) cnt--;
            st++;
        }

        if (cnt <= 2) sol = max(sol, en - st);
    }

    cout << sol;
    return 0;
}   