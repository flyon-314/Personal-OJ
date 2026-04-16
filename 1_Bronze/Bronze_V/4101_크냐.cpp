#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int first, second;
    while (true) {
        cin >> first >> second;

        if (first == 0 && second == 0)  break;
        

        if (first > second) cout << "Yes" << "\n";
        else  cout << "No" << "\n";
        
    }
}