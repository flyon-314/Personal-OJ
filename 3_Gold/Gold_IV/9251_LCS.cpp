#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
int lcs[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++){
            lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            if (s1[i - 1] == s2[j - 1]) lcs[i][j] = max(lcs[i][j], lcs[i - 1][j - 1] + 1);
            
        }
    }

    cout << lcs[s1.length()][s2.length()];
    return 0;
}