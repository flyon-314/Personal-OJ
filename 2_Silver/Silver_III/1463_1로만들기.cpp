#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
#include <unordered_map>
const int MAX = 9999999;
using namespace std;

int num[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    num[1] = 0;
    num[2] = 1;
    num[3] = 1;
    for (int i = 4; i <= n; i++) {
        num[i] = min(num[i - 1], min(i % 3 == 0 ? num[i / 3] : MAX, i % 2 == 0 ? num[i / 2] : MAX)) + 1;
    }
    cout << num[n];
    return 0;
}
