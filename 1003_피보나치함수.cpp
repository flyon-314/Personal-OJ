#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
#include <unordered_map>
using namespace std;

int pibo[2][41];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pibo[0][0] = 1;
    pibo[1][0] = 0;
    pibo[0][1] = 0;
    pibo[1][1] = 1;

    for (int i = 2; i < 41; i++) {
        pibo[0][i] = pibo[0][i - 1] + pibo[0][i - 2];
        pibo[1][i] = pibo[1][i - 1] + pibo[1][i - 2];
    }
    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        cout << pibo[0][num] << " " << pibo[1][num] << "\n";
    }
    
    return 0;
}
