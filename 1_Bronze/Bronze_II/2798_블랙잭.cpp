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

    int num[100];
    int n, m;
    int sol = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            for (int k = 0; k < n; k++) {
                if (k == j || k == i) continue;
                int temp = num[i] + num[k] + num[j];
                if (temp <= m && temp > sol) sol = temp;
            }
        }
    }
    cout << sol;
}