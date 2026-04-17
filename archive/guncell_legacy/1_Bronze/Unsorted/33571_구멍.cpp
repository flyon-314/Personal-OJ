#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s;
    getline(cin, s);  
    unordered_map<char,int> holes = {{'A', 1}, {'D', 1}, {'O', 1},{'P', 1}, {'Q', 1}, {'R', 1}, {'B', 2}, 
    {'@', 1}, {'a', 1}, {'b', 1}, {'d', 1},{'e', 1}, {'g', 1}, {'o', 1}, {'p', 1}, {'q', 1} };
    
    int sol = 0;
    for (char ch : s) {
        sol += holes[ch]; 
    }
    
    cout << sol << "\n";
    return 0;
}