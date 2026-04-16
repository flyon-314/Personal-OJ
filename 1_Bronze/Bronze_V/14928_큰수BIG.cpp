#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    const int MOD = 20000303;
    
    cin >> N;

    long long remainder = 0;

    for (char digit : N) {
        remainder = (remainder * 10 + (digit - '0')) % MOD;
    }

    cout << remainder << endl;

    return 0;
}
