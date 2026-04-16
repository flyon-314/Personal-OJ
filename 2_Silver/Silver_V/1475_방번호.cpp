#include <iosfwd>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num;
    int numArr[10] = {0};
    int big = 0;
    cin >> num;

    for (char s : num)
    {
        if (s == '6') numArr['9' - '0']++;
        else numArr[s - '0']++;
    }
    numArr[9] = numArr[9]/2 + numArr[9]%2;
    for (int i : numArr) big = max(big, i);
    cout << big << "\n";
    
    return 0;
}