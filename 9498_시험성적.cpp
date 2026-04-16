#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << (n >= 90 ? 'A' : n >= 80 ? 'B' : n >= 70 ? 'C' : n >= 60 ? 'D' : 'F');
    return 0;
}