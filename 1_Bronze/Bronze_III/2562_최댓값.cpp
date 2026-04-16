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

    int num = -1; 
    int idx = 0;
    int cur;

    for (int i = 1; i <= 9; i++) {
        cin >> cur;

        if (cur > num) {
            num = cur;
            idx = i;
        }
    }

    cout << num << "\n" << idx << "\n";
    return 0;
}