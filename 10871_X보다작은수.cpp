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

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < x) cout << temp << " ";
    }

    return 0;
}