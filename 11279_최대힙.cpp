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
    cin >> n;
    priority_queue<int> q;

    while (n--) {
        int x;
        cin >> x;
        if (x != 0) q.push(x);
        else if (!q.empty()) {
            cout << q.top() << "\n";
            q.pop();
        }
        else cout << "0\n";
    }
}