#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> setter;
    int input;

    for (int i = 0; i < 10; ++i) {
        cin >> input;
        setter.insert(input % 42);
    }

    cout << setter.size();
}