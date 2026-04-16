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

    cout << ((n % 4 == 0 && (n % 100 != 0 || n % 400 == 0)) ? 1 : 0) ;
    return 0;
}