#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t; // 테스트 케이스 개수 입력
    
    while (t--) {
        long long x, y;
        cin >> x >> y; // 두 정수 입력
        cout << (x + y) << "\n"; // 합 출력
    }
    
    return 0;
}
