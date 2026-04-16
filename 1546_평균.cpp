#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

double num[1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    double n;
    double max_num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        max_num = max(num[i], max_num);
    }

    double sum = 0;
    for (int i = 0 ; i < n; i++) {
        num[i] = num[i] / max_num * 100;
        sum += num[i];
    }
    cout << fixed << setprecision(20) << sum / n;
    
    return 0;
}