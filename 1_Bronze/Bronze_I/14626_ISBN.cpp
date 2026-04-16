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

    int sum = 0;
    int check = 0;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == '*') check = i % 2  == 1 ? 3 : 1;
        else {
            sum += i % 2 == 1 ? (s[i] -'0') * 3 : (s[i] - '0');
        }
    }


    for (int i = 0 ; i < 10 ; i++) {
        if ((check * i + sum) % 10 == 0) cout << i;
    }

    return 0;
}
