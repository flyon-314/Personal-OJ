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

    int a, b, v;
    cin >> a >> b >> v;

    cout << (v - b - 1) / (a - b) + 1;
    return 0;
}