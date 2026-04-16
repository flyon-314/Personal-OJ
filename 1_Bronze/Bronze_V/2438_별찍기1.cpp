#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++ ){
        for (int j = 0 ; j < i ; j++){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}