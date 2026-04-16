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
    int n;
    
    cin >> s;
    cin >> n;

    cout << s[n - 1];
    return 0;
}
