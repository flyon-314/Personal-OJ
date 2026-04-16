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
#include <stack>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue <int> q;

    while (n--) {
        string s;
        cin >> s;

        if (s == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (s == "pop") {
            if (q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (s == "size") {
            cout << q.size() << "\n";
        }
        else if (s == "empty") {
            if (q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (s == "front") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if (s == "back") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
}   