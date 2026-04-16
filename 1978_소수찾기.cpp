#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

bool num[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    
    
    for (int i = 2; i < 1001; i++) num[i] = true;

    for (int i = 2; i < 1001; i++) {
        if (num[i] == false) continue;
        for (int j = i * i; j < 1001; j += i) num[j] = false; 
    }

    int n, count = 0;
    cin >> n;

    while (n--) {
        int t;
        cin >> t;
        if (num[t] == true) count++;
    }

    cout << count;
    return 0;
}