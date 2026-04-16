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

    int T;
    cin >> T;

    while (T--) {
        int r;
        string s;
        cin >> r >> s;

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < r; j++) cout << s[i];
        }
        cout << "\n";
    }
}