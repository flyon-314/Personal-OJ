#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <climits>
#include <stack>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector <int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int cut = round(n * 0.15);
    int new_n = n - cut * 2;

    double sum = 0;
    for (int i = cut ; i < n - cut ; i++) sum += arr[i];

    cout << round(sum / new_n) ;
}   