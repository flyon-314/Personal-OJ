#include <iosfwd>
#include <iostream>
#include <stdio.h>
int num[3][100001];
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    num[0][0] = 1;
    num[1][0] = 1;
    num[2][0] = 1;

    for (int i = 1; i < n; i++)
    {
        num[0][i] = (num[1][i - 1] + num[2][i - 1] +num[0][i - 1]) % 9901;
        num[1][i] = (num[0][i - 1] + num[2][i - 1]) % 9901;
        num[2][i] = (num[1][i - 1] + num[0][i - 1]) % 9901;
        
    }
    cout << (num[0][n - 1] + num[1][n - 1] + num[2][n - 1]) % 9901 << "\n";
    return 0;
}
    