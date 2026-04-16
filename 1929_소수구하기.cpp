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

bool narr[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;

    cin >> m >> n;
    
    narr[0] = true;
    narr[1] = true;
    
    for (int i = 2 ; i <=  sqrt(n) ; i++) {
        if (narr[i]) continue;
        for (int j = i * i ; j <= n ; j += i)  narr[j] = true;
    }

    for (int i = m ; i <= n ; i++) if (!narr[i]) cout << i << "\n";
}   