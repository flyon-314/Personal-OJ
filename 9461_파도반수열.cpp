#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
constexpr int MAX = 9999999;
using namespace std;

long long triangle[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    triangle[1] = 1; triangle[2] = 1; triangle[3] = 1;
    for (int i = 4; i < 101; i++) {
        triangle[i] = triangle[i - 2] + triangle[i - 3];
    }
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        cout << triangle[n] << "\n";
    }
    return 0;
}
