#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n, m;
    cin >> n >> m;
    unordered_map<string, int> map;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map.insert({s, i});
    }
    vector <string> v;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (map.find(s) != map.end()) v.push_back(s);
    }
    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    
    return 0;
}