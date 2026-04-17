#include <bits/stdc++.h>

using namespace std;
int coin[25];
int main() {
    ios::sync_with_stdio(0);;
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int dp[10001]={0,};
        int n;
        int value;
        
        cin>>n;
        for(int i=0;i<n;i++) cin>>coin[i];
        
        cin>>value;
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coin[i];j<=value;j++) dp[j]+=dp[j-coin[i]];
                
        }
        cout<<dp[value]<<"\n";
    }
    return 0;
}