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

    int sol = 1;
    long long n;
    cin >> n;

    for (int i = 1 ; n > 1  ; i++) {
        n -= i * 6;
        sol++;
    }
    cout << sol;
}