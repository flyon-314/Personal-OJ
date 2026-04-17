#include <iostream>

using namespace std;

int main() {

    int n;

    while (cin >> n && n != 0) {

        int total = n * (n + 1) / 2;

        cout << total << endl;

    }

    return 0;

}