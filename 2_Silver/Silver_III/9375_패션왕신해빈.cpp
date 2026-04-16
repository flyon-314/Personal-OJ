#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
constexpr int MAX = 9999999;
using namespace std;

int num[12];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        unordered_map<string, int> map;
        int n;
        string s1,s2;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s1 >> s2;
            if (map.find(s2) != map.end()) map[s2]++;
            else map[s2] = 1;
        }
        
        int count = 1;
        for (auto it = map.begin(); it != map.end(); ++it) {
            count *= it->second + 1;
        }
        
        cout << count - 1<< "\n";
        
    }
    return 0;
}
