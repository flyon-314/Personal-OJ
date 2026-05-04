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
    int idx = lcs[s1.length()][s2.length()];
    int r = s1.length();
    int c = s2.length();
    string sol = "";
    
    while (idx != 0) {
        while (lcs[r][c] == lcs[r - 1][c]) r--;
        while (lcs[r][c] == lcs[r][c - 1]) c--;
        
        sol += s2[c - 1];
        r--; c--;
        idx--;
    }

    int len = sol.length();
    cout << len << "\n";
    if (len != 0)for (int i = len - 1; i >= 0; i--) cout << sol[i];
    return 0;
}