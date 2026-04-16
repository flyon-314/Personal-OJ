#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int my_gcd(int a, int b)
{
    if (b == 0) return a;
    return my_gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    int gcd = my_gcd(a, b);
    
    cout << gcd << "\n" << (a * b) / gcd;
    return 0;
}