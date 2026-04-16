#include <iosfwd>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    cout << n + x << "\n";

    return 0;
}