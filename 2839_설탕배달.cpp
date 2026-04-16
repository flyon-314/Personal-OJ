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

    int n;
    cin >> n;

    int anw = 0;
    while (n >= 0) {
        if (n % 5 == 0) {
            anw += n / 5;
            cout << anw ;
            return 0;
        }
        n -= 3;
        anw++;
    }

    cout << -1;
    return 0;
    
}   