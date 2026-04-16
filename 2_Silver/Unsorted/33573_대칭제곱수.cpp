#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--){
        long long N;
        cin >> N;

        long long root = sqrt(N);
        if (root * root != N) {
            cout << "NO\n";
            continue;
        }
        
        string s = to_string(N);
        reverse(s.begin(), s.end());
        N = stoll(s);

        root = sqrt(N);
        if (root * root != N) {
            cout << "NO\n";
            continue;
        }
        else cout << "YES\n";
    }

}