#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int num[21];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (s == "add") {
            int n;
            cin >> n;
            num[n] ? 0 : num[n] = 1;
        }
        else if (s == "remove") {
            int n;
            cin >> n;
            num[n] ? num[n] = 0 : 0;
        }
        else if (s == "check") {
            int n;
            cin >> n;
            cout << num[n] << "\n";
        }
        else if (s == "toggle") {
            int n;
            cin >> n;
            num[n] ? num[n] = 0 : num[n] = 1;
        }
        else if (s == "all") {
            for (int i = 0; i < 21; i++) num[i] = 1;
        }
        else if (s == "empty") {
            for (int i = 0; i < 21; i++) num[i] = 0;
        }
    }
    return 0;
}