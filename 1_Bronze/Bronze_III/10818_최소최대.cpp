#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    int min_num = 1000001; 
    int max_num = -1000001; 

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num < min_num) min_num = num;
        if (num > max_num) max_num = num;
    }

    cout << min_num << " " << max_num;
    return 0;
}