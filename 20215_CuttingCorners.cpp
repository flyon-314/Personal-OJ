#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h;
    cin >> w >> h;

    double diagonal_length = sqrt(w * w + h * h);
    double rectangle_length = w + h;
    double difference = rectangle_length - diagonal_length;

    cout << fixed << setprecision(6) << difference << endl;

    return 0;
}
