#include <iosfwd>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int numArr[2000001];
int numArr2[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    int sol = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> numArr2[i];
        numArr[numArr2[i]]++;
    }
    cin >> x;

    for (int i = 0 ; i < n; i++)
    {
        if (x - numArr2[i] >= 0 && numArr[x - numArr2[i]] == 1 && x / numArr2[i] != 2)
        {
            sol++;
            numArr[x - numArr2[i]]--;
            numArr[numArr2[i]]--;
        }
    }

    cout << sol << "\n";
    return 0;
}