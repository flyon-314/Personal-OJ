#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int num[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        num[t]++;
    }

    for (int i = 0; i < 100001; i++) {
        if (!num[i])continue;
        for (int j = 0 ; j < num[i]; j++) cout << i << "\n";
    }
    return 0;
}