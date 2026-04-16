#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int l;
    string s;
    cin >> l >> s;

    long long r = 31;
    long long m = 1234567891;
    long long hash = 0;
    long long pow_r = 1;

    for (int i = 0; i < l; i++) {
        long long a_i = s[i] - 'a' + 1;
        hash = (hash + (a_i * pow_r)) % m;
        pow_r = (pow_r * r) % m;
    }

    cout << hash;
}