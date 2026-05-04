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

    string s;
    cin >> s;

    int cut = 0;
    int sol = 0;
    bool sub = false;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == '+' || s[i] == '-') {
            sol += sub ? -stoi(s.substr(cut, i - cut )) : stoi(s.substr(cut, i - cut));
            cut = i + 1;
            if (s[i] == '-') sub = true;
        }
    }
    sol += sub ? -stoi(s.substr(cut, s.length() - cut)) : stoi(s.substr(cut, s.length() - cut));
    cout << sol;
    return 0;
}
