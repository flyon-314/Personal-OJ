#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
long long div(long long a, long long b, long long c)
{
    if (b == 1) return a % c;
    long long mid =  b / 2 ;

    if (b % 2 == 1) return div(a, mid +1, c)  * div (a, mid, c) % c;
    else return div(a, mid, c) * div(a, mid, c) % c;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << div(a, b, c);
    return 0;
}
