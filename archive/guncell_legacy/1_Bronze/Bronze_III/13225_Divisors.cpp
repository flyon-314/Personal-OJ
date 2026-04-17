#include <iostream>
#include <cmath>

using namespace std;

int countDivisors(int n) {
    int count = 0;
    int sqrtN = sqrt(n);
    for (int i = 1; i <= sqrtN; i++) {
        if (n % i == 0) {
            // i와 n/i가 같다면 중복되지 않도록 1개만 카운트
            if (i * i == n)
                count++;
            else
                count += 2;
        }
    }
    return count;
}

int main() {
    int C;
    cin >> C;
    
    while (C--) {
        int n;
        cin >> n;
        cout << n << " " << countDivisors(n) << "\n";
    }
    
    return 0;
}
