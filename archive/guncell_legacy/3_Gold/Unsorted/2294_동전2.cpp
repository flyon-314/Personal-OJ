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
    int coin[101];
    int dp[10001];
    int main(   )
    {
        ios_base::sync_with_stdio();
        cin.tie(NULL);
        cout.tie(NULL);
        int n, k;
        cin >> n >> k;
        for (int i = 0 ; i <= k ; i++) dp[i] = 999999;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp > 10000) continue;
            coin[i] = temp;
            dp[temp] = 1;
        }
        sort(coin, coin + n);

        for (int i = 1; i <= k; i++)
        {
            for (int j = 0 ; j < n; j++)
            {
                if (i - coin[j] >= 0 && dp[i - coin[j]] != 999999)
                {
                    dp[i] = min(dp[i], dp[i - coin[j]] + 1);
                }
            }
        }
        if (dp[k] != 999999) cout << dp[k] ;
        else cout << - 1 ;
    }
