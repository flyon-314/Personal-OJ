#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int apart[15][15];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    apart[0][0] = 1;
    for (int i = 1; i < 15; i++) apart[0][i] = apart[0][i - 1] + i + 1;
    for (int i = 1; i < 15; i++) {
        apart[i][0] = apart[i - 1][0];
        for (int j = 1; j < 15; j++) {
            apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
        }
    }
    int t;
    cin >> t;
    
    while (t--) {
        int k, n;
        cin >> k >> n;
        cout << apart[k][n - 1] - (n == 1 ? 0 : apart[k][n - 2]) << "\n";
    }
    return 0;
}