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

    unordered_map<string, string>poke_name;
    unordered_map<string, string>poke_id;
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name ;
        poke_name[name] = to_string(i);
        poke_id[to_string(i)] = name;
    }
    while (m--) {
        string command;
        cin >> command;
        if (command[0] - '0' >=0 && command[0] - '0' < 10) cout << poke_id[command] << "\n";
        else cout << poke_name[command] << "\n";
    }
    return 0;
}