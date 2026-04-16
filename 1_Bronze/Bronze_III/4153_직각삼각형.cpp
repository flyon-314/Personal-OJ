#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num[3];

    while (cin >> num[0] >> num[1] >> num[2] && num[0] != 0) {
        sort(num, num + 3);
        if (num[0] * num[0] + num[1] * num[1] == num[2] * num[2]) cout << "right\n";
        else cout << "wrong\n";
    }
    return 0;
}