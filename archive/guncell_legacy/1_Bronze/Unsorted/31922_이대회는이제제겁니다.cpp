#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, P, C;
    cin >> A >> P >> C;

    int prize1 = A + C;
    
    int prize2 = P;

    int maxPrize = max(prize1, prize2);

    cout << maxPrize << endl;

    return 0;
}
