#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
#include <unordered_map>
using namespace std;

int p[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p, p + n);

    int sol = p[0];
    for (int i = 1; i < n; i++) {
        p[i] += p[i - 1];
        sol += p[i];
    }
    cout << sol;
    return 0;
}