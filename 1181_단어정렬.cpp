#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;
bool comp(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)  cin >> words[i];
    sort(words.begin(), words.end(), comp);

    for (int i = 0; i < n; i++) {
        if (i != 0 && words[i - 1] == words[i]) continue;
        cout << words[i] << "\n";
    }
    return 0;
}