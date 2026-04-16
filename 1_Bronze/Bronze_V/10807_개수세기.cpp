#include <iosfwd>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int num[201];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num[temp + 100]++;
    }

    int v;
    cin >> v;

    cout << num[v + 100] << endl;
}