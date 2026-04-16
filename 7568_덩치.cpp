#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector <pair <int, int> > v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (pair <int, int> i : v) {
        int count = 0;
        for (pair <int, int> j : v) {
            if (j.first > i.first && j.second > i.second) count++;
        }
        cout << ++count << " ";
    }
}