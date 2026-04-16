#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    string s;

    while (cin >> s && s != "0" ) {
        bool flag = false;
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1]) {
                cout << "no\n";
                flag = true;
                break;
            }    
        }
        if (!flag)cout << "yes\n" ;
    }
    
    return 0;
}