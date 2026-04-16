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

    int h, m;
    cin >> h >> m;

    if (m < 45) {
        m += 60;
        m -= 45;
        h -= 1;
        if (h < 0) h = 23;
    }
    else {
        m -= 45;
    }

    cout << h << " " << m;
    return 0;
}