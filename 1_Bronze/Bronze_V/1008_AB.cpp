#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(12) << a / b ;
    return 0;
}