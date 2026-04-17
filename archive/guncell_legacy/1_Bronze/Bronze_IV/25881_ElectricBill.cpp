#include <bits/stdc++.h>
using namespace std;

int main() {
    int rate1, rate2;
    cin >> rate1 >> rate2;
    int n;
    cin >> n;
    vector<int> consumptions(n);
    for (int i = 0; i < n; ++i) {
        cin >> consumptions[i];
    }
    for (int consumption : consumptions) {
        int bill;
        if (consumption <= 1000) {
            bill = consumption * rate1;
        } else {
            bill = 1000 * rate1 + (consumption - 1000) * rate2;
        }
        cout << consumption << " " << bill << "\n";
    }
    return 0;
}
