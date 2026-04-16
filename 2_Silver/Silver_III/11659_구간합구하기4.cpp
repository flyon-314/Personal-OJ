#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int num[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        num[i] = temp + num[i - 1];
    }

    while (t--) {
        int x1, x2;
        cin >> x1 >> x2;
        cout << num[x2] - num[x1 - 1] << "\n";        
    }
    return 0;
}
