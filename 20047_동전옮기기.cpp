#include <iosfwd>
#include <iostream>
#include <stdio.h>

bool dp[3][10001];
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int i, j;
    cin >> i >> j;

    s1 = " " + s1;
    s2 = " " + s2;
    i++; j++;
    string s = " ";

    for (int k = 1; k <=  n; ++k)
    {
        if (k != i && k != j) s += s1[k];
    }
    dp[0][0] = 1;
    for (int k = 1; k <= n; ++k)
    {
        if (dp[0][k - 1] && s2[k] == s[k]) dp[0][k] = 1;
        if ((dp[1][k - 1] && s2[k] == s[k-1]) || (dp[0][k - 1] && s2[k] == s1[i])) dp[1][k] = 1;
        if ((dp[2][k - 1] && s2[k] == s[k-2]) || (dp[1][k - 1] && s2[k] == s1[j])) dp[2][k] = 1;
    }
    
    if (dp[2][n]) cout << "YES";
    else cout << "NO";
    return 0;
}