#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int initialPrice;
    cin >> initialPrice;

    vector<int> dailyChanges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> dailyChanges[i];
    }

    int finalPrice = initialPrice;
    for (int i = 0; i < n - 1; ++i) {
        finalPrice += dailyChanges[i];
    }

    cout << finalPrice << endl;

    return 0;
}
