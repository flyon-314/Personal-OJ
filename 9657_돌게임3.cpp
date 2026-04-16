#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(   )
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    int stone[1001] = {0};
    int n;
    cin >> n;

    stone[1] = 1;
    stone[3] = 1;
    stone[4] = 1;
    stone[5] = 1;
    for (int i = 6 ;i <= n; i++)
    {
        if (stone[i-1] == 1 && stone[i-3] == 1 && stone[i-4] == 1 ) stone[i] = 0;
        else stone[i] = 1;
    }

    if (stone[n] == 1) cout << "SK\n";
    else cout << "CY\n";    
    
}
    