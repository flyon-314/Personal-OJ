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

    long long a, b;
    cin >> a >> b;

    queue <long long> q;
    q.push(a);
    long long count = 0;
    
    while (!q.empty()) {
        long long s = q.size();

        while (s--) {
            long long p = q.front();
            if (p == b) {
                cout << count + 1<< "\n";
                return 0;
            }
            q.pop();
            if (p * 2 <= b)q.push(p * 2 );
            if (p * 10 + 1 <= b) q.push(p * 10 + 1);
        }
        count++;
    }
    cout << -1;
    return 0;
}
