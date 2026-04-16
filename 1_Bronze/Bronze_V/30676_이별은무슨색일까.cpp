#include <iosfwd>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n <= 781 &&  n >= 620 ) cout << "Red\n";
    else if (n < 620 && n >= 590) cout << "Orange\n";
    else if (n < 590 && n >= 570) cout << "Yellow\n";
    else if (n < 570 && n>= 495) cout << "Green\n";
    else if (n < 495 && n >= 450) cout << "Blue\n";
    else if (n < 450 && n >= 425) cout << "Indigo\n";
    else if (n < 425 && n >= 380) cout << "Violet\n";
}
    