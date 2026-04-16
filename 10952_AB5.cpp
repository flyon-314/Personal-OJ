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

    int a, b;

    while (cin >> a >> b && a != 0 && b != 0) {
        cout << a + b << "\n";
    }
    return 0;
}