#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int factorial(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        num *= i;
    }
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int answer = factorial(n) / (factorial(k) * factorial(n - k));

    std::cout << answer;
    return 0;
}
