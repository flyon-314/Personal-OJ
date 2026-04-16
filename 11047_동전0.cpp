#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
#include <unordered_map>
using namespace std;

int coin[11];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int n, k;
    cin >> n >> k;
    int sol = 0;
    
    for (int i = 0; i < n; i++) cin >> coin[i];
    
    for (int i = n - 1; i >= 0; i--) {
        sol += k / coin[i];
        k %= coin[i];
    }
    cout << sol;
    
    return 0;
}