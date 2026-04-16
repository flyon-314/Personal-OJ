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

int num[12];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    num[1] = 1; num[2] = 2; num[3] = 4;
    for (int i = 4; i < 12; i++) num[i] = num[i - 1] + num[i - 2] + num[i - 3];

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        cout << num[x] << "\n";
    }
    
    return 0;
}
