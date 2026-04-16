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

    int n;
    cin >> n;
    
    int min_dp1, min_dp2, min_dp3;
    int max_dp1, max_dp2, max_dp3;
    int n1, n2, n3;
    
    cin >> n1 >> n2 >> n3;
    
    min_dp1 = n1; min_dp2 = n2; min_dp3 = n3;
    max_dp1 = n1; max_dp2 = n2; max_dp3 = n3;
    for (int i = 1 ; i < n ; i++) {
        cin >> n1 >> n2 >> n3;
        int a, b, c;
        a = n1 + min(min_dp1, min_dp2);
        b = n2 + min(min_dp1, min(min_dp2, min_dp3) );
        c = n3 + min(min_dp3, min_dp2);
        min_dp1 = a; min_dp2 = b; min_dp3 = c;
        
        a = n1 + max(max_dp1, max_dp2);
        b = n2 + max(max_dp2, max(max_dp1, max_dp3));
        c = n3 + max(max_dp3, max_dp2);
        max_dp1 = a; max_dp2 = b; max_dp3 = c;
    }
    cout << max(max_dp1, max(max_dp2, max_dp3))<< " ";
    cout << min(min_dp1, min(min_dp2, min_dp3)) ;
    
    return 0;
}