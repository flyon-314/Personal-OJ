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

    int cnt = 0;
    int num = 666;

    while (true) {
        string s = to_string(num);
        
        if (s.find("666") != string::npos) cnt++;
        if (cnt == n) {
            cout << num ;
            break;
        }

        num++;
    }
}