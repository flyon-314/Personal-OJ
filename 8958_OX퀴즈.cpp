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

    int t;
    cin >> t;

    while (t--) {
        string str;
        cin >> str;

        int score = 0;
        int cur = 0;

        for (char c : str) {
            if (c == 'O') {
                cur++;
                score += cur;
            }
            else {
                cur = 0;
            }
        }

        cout << score << "\n";
    }
}