#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, p, clothes[6];
    int t_num = 0;
    
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> clothes[i];
    }
    cin >> t >> p;

    for (int i = 0; i < 6; i++) {
        t_num += clothes[i] % t != 0 ? clothes[i] / t + 1 : clothes[i] / t;
    }

    cout << t_num << "\n" << n / p << " " << n % p;
    
    return 0;
}