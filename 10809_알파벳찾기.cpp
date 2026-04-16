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
    
    string s;
    cin >> s;

    vector<int> v(26, -1);

    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';

        if (v[idx] == -1)  v[idx] = i;
    }

    for (int i = 0; i < 26; i++)  cout << v[i] << (i == 25 ? "" : " ");

    return 0;
}