#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\n";
    }
    return 0;
}