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

    priority_queue<int, vector<int>, greater<int>>q;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (q.empty()) cout << 0 << "\n";
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else q.push(x);
    }
    return 0;
}
