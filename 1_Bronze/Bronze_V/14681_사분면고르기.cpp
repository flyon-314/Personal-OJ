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
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;

    cin >> x;
    cin >> y;

    if (x > 0) {
        if (y > 0) cout << 1 << "\n";
        else cout << 4 << "\n";
    }
    else {
        if (y > 0)  cout << 2 << "\n";
        else  cout << 3 << "\n";
    }
    
    return 0;
    
}   