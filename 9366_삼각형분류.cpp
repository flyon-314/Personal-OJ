#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int i = 1; i <= T; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if (a >= b + c || b >= a + c || c >= a + b)  cout << "Case #" << i << ": invalid!\n";  

        else if(a == b && b ==c) cout << "Case #" << i << ": equilateral\n";  

        else if (a == b || a == c  || b ==c )  cout << "Case #" << i << ": isosceles\n";  

        else  cout << "Case #" << i << ": scalene\n";  

    }
}