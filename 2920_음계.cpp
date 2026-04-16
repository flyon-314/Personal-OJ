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

    int scale[8];
    bool isAscending = true;
    bool isDescending = true;

    for (int i = 0; i < 8; i++) cin >> scale[i];

    for (int i = 0; i < 7; i++) {
        if (scale[i] < scale[i + 1])  isDescending = false;
        else if (scale[i] > scale[i + 1]) isAscending = false;
    }

    if (isAscending) cout << "ascending" << "\n";
    else if (isDescending) cout << "descending" << "\n";
    
    else  cout << "mixed" << "\n";
}